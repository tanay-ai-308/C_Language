#include<stdio.h>
int MyStrNCmp(const char *, const char *, int);
int main (void)
{
	int iNo;
	int iRet;
	char szStr1[30];
	char szStr2[30];

	printf("Enter string 1 :-\n\t\t");						//Enter string 1 :-
	gets(szStr1);											//                tanay dherange
	printf("Enter string 2 :-\n\t\t");						//Enter string 2 :-
	gets(szStr2);											//                tanay suresh dherange
	printf("Enter no characters to be checked :-\n\t\t");	//
	scanf("%d",&iNo);										//

	iRet = MyStrNCmp(szStr1,szStr2,iNo);

	if(iRet==0)
		printf("\nBoth strings are same.\n");
	else
		printf("\nStrings are not same.\n");		//Strings are not same.

	return 0;
}
int MyStrNCmp(const char * pszStr1, const char * pszStr2, int iNo)
{
	int iCounter = 0;

	while(*pszStr1 != '\0' && *pszStr2 != '\0' && iCounter<iNo)
	{
		if(*pszStr1 - *pszStr2 < 0)
			return (*pszStr1-*pszStr2);
		else if(*pszStr1 - *pszStr2 > 0)
			return (*pszStr1-*pszStr2);
		pszStr1++;
		pszStr2++;
		iCounter++;
	}
	return 0;
}