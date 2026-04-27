#include<stdio.h>
int MyStrCmpI(const char *, const char *);
int main (void)
{
	int iRet;
	char szStr1[30];
	char szStr2[30];

	printf("Enter string 1 :-\n\t\t");						//Enter string 1 :-
	gets(szStr1);											//                tanay Dherange
	printf("Enter string 2 :-\n\t\t");						//Enter string 2 :-
	gets(szStr2);											//                tanay dherange

	iRet = MyStrCmpI(szStr1,szStr2);

	if(iRet==0)
		printf("\nBoth strings are same.\n");		//Both strings are same.
	else
		printf("\nStrings are not same.\n");		

	return 0;
}
int MyStrCmpI(const char * pszStr1, const char * pszStr2)
{
	while(*pszStr1 != '\0' && *pszStr2 != '\0')
	{
		if(((*pszStr1 - *pszStr2 < 0) && (*pszStr1 - *pszStr2 != -32)) && (*pszStr1 <= 'A' && *pszStr1 >= 'Z'))
			return (*pszStr1-*pszStr2);
		else if(((*pszStr1 - *pszStr2 > 0) && (*pszStr1 - *pszStr2 != 32)) && (*pszStr1 <= 'A' && *pszStr1 >= 'Z'))
			return (*pszStr1-*pszStr2);
		pszStr1++;
		pszStr2++;
	}
	return 0;
}