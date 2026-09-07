#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600
#define MAX 3

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevhInstance, LPSTR pszCmdLine, int iCmdShow)
{
	int cxScreen;
	int cyScreen;
	MSG msg;
	int iRet;
	HWND hwnd;
	WNDCLASSEX wndClass;
	TCHAR szClassName[] = TEXT("MyClass");

	wndClass.cbSize = sizeof(WNDCLASSEX);

	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;

	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = szClassName;

	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(NULL, TEXT("RegistorClassEx Failure"), szClassName, MB_OK);
		exit(0);
	}

	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	hwnd = CreateWindow(
		szClassName,
		TEXT("My First Wnidow."),
		WS_OVERLAPPEDWINDOW,
		(cxScreen / 2) - (WINDOW_WIDTH / 2),		//X POINT
		(cyScreen / 2) - (WINDOW_HEIGHT / 2),		//Y POINT
		WINDOW_WIDTH,						//WIDTH
		WINDOW_HEIGHT,						//HEIGHT
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (NULL == hwnd)
	{
		MessageBox(NULL, TEXT("Create Window Failed."), szClassName, MB_OK);
		exit(0);
	}

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while ((iRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (iRet == -1)
		{
			MessageBox(NULL, TEXT("Get Message Failed."), szClassName, MB_OK);
			exit(0);
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	int iRow;
	int iCol;
	int x;
	int y;
	int iWidth;
	int iHeight;
	static int winner = 0;
	PAINTSTRUCT ps;
	static int iTurn = 1;
	int clientWidth;
	int clientHeight;
	RECT rc;
	int iBoxWidth = WINDOW_WIDTH / 3;
	int iBoxHeight = WINDOW_HEIGHT / 3;
	static int Arr[MAX][MAX] = { 0 };

	switch (iMessage)
	{
	case WM_RBUTTONDOWN:

		x = LOWORD(lParam);
		y = HIWORD(lParam);


		iCol = x / iBoxWidth;
		iRow = y / iBoxHeight;

		// ---------- Show winner & reset ----------

		if ((iRow < MAX) && (iCol < MAX))
		{
			if (!Arr[iRow][iCol])
			{
				if (iTurn == 1)
				{
					Arr[iRow][iCol] = 1;
					iTurn = 2;
				}
			}
			else
			{
				if (Arr[iRow][iCol] == 2)
					MessageBox(hwnd, TEXT("Box is already taken by 0.."), TEXT("Message"), MB_OK);

			}

		}

		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONDOWN:

		x = LOWORD(lParam);
		y = HIWORD(lParam);


		iCol = x / iBoxWidth;
		iRow = y / iBoxHeight;

		// ---------- Show winner & reset ----------
					
		if ((iRow < MAX) && ( iCol < MAX))
		{
			if (!Arr[iRow][iCol])
			{
				if(iTurn == 2)
				{
					Arr[iRow][iCol] = 2;
					iTurn = 1;
				}
			}
			else
			{
				if (Arr[iRow][iCol] == 1)
					MessageBox(hwnd, TEXT("Box is already taken by X.."), TEXT("Message"), MB_OK);
			}

		}

		InvalidateRect(hwnd, NULL, TRUE);
		break ;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);

		clientWidth = rc.right - rc.left;
		clientHeight = rc.bottom - rc.top;

		iWidth = clientWidth / 3;
		iHeight = clientHeight / 3;
		for (iRow= 0; iRow < MAX; iRow++)
		{
			for (iCol = 0; iCol < MAX;iCol++)
			{
				int iLeft = iCol * iWidth;
				int iTop = iRow * iHeight;
				int iRight = iLeft + iWidth;
				int iBottom = iTop + iHeight;

				Rectangle(hdc, iLeft, iTop, iRight, iBottom);

				if (Arr[iRow][iCol] == 1)
				{
					MoveToEx(hdc, iLeft, iTop, NULL);
					LineTo(hdc, iRight, iBottom);

					MoveToEx(hdc, iRight,iTop, NULL);
					LineTo(hdc, iLeft, iBottom);
				}
				if (Arr[iRow][iCol] == 2)
				{
					Ellipse(hdc, iLeft, iTop, iRight, iBottom);
				}
			}
		}

		// ---------- Winner Check ----------

		// Rows
		for (iRow = 0; iRow < 3; iRow++)
		{
			if (Arr[iRow][0] != 0 &&
				Arr[iRow][0] == Arr[iRow][1] &&
				Arr[iRow][1] == Arr[iRow][2])
			{
				winner = Arr[iRow][0];
			}
		}

		// Columns
		for (iCol = 0; iCol < 3; iCol++)
		{
			if (Arr[0][iCol] != 0 &&
				Arr[0][iCol] == Arr[1][iCol] &&
				Arr[1][iCol] == Arr[2][iCol])
			{
				winner = Arr[0][iCol];
			}
		}

		// Diagonals
		if (Arr[0][0] != 0 && Arr[0][0] == Arr[1][1] && Arr[1][1] == Arr[2][2])
			winner = Arr[0][0];

		if (Arr[0][2] != 0 && Arr[0][2] == Arr[1][1] && Arr[1][1] == Arr[2][0])
			winner = Arr[0][2];

		if (winner)
		{
			if (winner == 1)
			{
				MessageBox(hwnd, TEXT("X is Winner!"), TEXT("Game Over"), MB_OK);
				MessageBox(hwnd, TEXT("x will star the game"), TEXT("Game winner"), MB_OK);
				iTurn = 1;
				InvalidateRect(hwnd, NULL, TRUE);
			}
			else
			{
				MessageBox(hwnd, TEXT("O is Winner!"), TEXT("Game Over"), MB_OK);
				MessageBox(hwnd, TEXT("O will star the game"), TEXT("Game winner"), MB_OK);
				iTurn = 2;
				InvalidateRect(hwnd, NULL, TRUE);
			}

			// Reset board
			for (iRow = 0; iRow < 3; iRow++)
				for (iCol = 0; iCol < 3; iCol++)
					Arr[iRow][iCol] = 0;

			winner = 0;
			return 0;
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}
