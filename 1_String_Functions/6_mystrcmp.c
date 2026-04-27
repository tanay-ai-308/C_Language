#include<stdio.h>
int MyStrCmp(const char *, const char *);
int main (void)
{
	int iRet;
	char szStr1[30];
	char szStr2[30];

	printf("Enter string 1 :-\n\t\t");						//Enter string 1 :-
	gets(szStr1);											//                tanay dherange
	printf("Enter string 2 :-\n\t\t");						//Enter string 2 :-
	gets(szStr2);											//                tanay suresh dherange

	iRet = MyStrCmp(szStr1,szStr2);

	if(iRet==0)
		printf("\nBoth strings are same.\n");
	else
		printf("\nStrings are not same.\n");		//Strings are not same.

	return 0;
}
int MyStrCmp(const char * pszStr1, const char * pszStr2)
{
	while(*pszStr1 != '\0' && *pszStr2 != '\0')
	{
		if(*pszStr1 - *pszStr2 < 0)
			return (*pszStr1-*pszStr2);
		else if(*pszStr1 - *pszStr2 > 0)
			return (*pszStr1-*pszStr2);
		pszStr1++;
		pszStr2++;
	}
	return 0;
}