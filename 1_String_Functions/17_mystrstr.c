#include<stdio.h>
char * MyStrStr(const char *,const char *);
int main(void)
{
	char szStr1[30];
	char szStr2[30];
	char *pPtr;

	printf("\nEnter the string :- \n\t");							//Enter the string :- my name is tanay
	gets(szStr1);
	printf("\nEnter the string to be found :- \n\t");				//Enter the string to be found :- is tanay
	gets(szStr2);

	pPtr=MyStrStr(szStr1,szStr2);

	if(NULL==pPtr)
		printf("\nstring not found.\n");
	else
	{
		printf("\nstring is found at %d location.",(pPtr-szStr1)+1);		//string is found at 9 location.
		printf("\nstring found in '%s'\n",pPtr);							//string found in 'is tanay'
	}

	return 0;
}
char * MyStrStr(const char *pszStr, const char *pszSubStr)
{
	int iCounter1 = 0;
	int iCounter2 = 0;

	while(pszStr[iCounter1] != '\0')
	{
		while(pszStr[iCounter1] != pszSubStr[iCounter2])
			iCounter1++;

		while(pszStr[iCounter1] == pszSubStr[iCounter2] && pszSubStr[iCounter2] != '\0')
		{
			iCounter1++;
			iCounter2++;
		}

		if(pszSubStr[iCounter2] == '\0')
			return (char *) &pszStr[iCounter1-iCounter2];
		else
		{
			iCounter1++;
			continue;
		}
	}
	return NULL;
}