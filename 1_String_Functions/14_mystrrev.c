#include<stdio.h>

char * MyStrRev(char *);

int main(void)
{
	char szStr[30];

	printf("\nEnter the string :- ");			//Enter the string :- tanay dherange
	gets(szStr);

	MyStrRev(szStr);

	printf("\nString in reverse order is :-\n\t\t");		//String in reverse order is :-
	puts(szStr);											//                egnrehd yanat

	return 0;
}
char * MyStrRev(char *pszStr)
{
	int iCounter1;
	int iCounter2;
	char *ptemp = pszStr;

	for(iCounter1 = 0 ; *(ptemp) != '\0' ; ptemp++ ,iCounter1++);

	ptemp--;
	iCounter2 = 0;
	while(iCounter1/2 != iCounter2)
	{
		pszStr[iCounter2] = pszStr[iCounter2] ^ *(ptemp);
		*(ptemp) = pszStr[iCounter2] ^ *(ptemp);
		pszStr[iCounter2] = pszStr[iCounter2] ^ *(ptemp);

		ptemp--;
		iCounter2++;
	}

	return pszStr;
}