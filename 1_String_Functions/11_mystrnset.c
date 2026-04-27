#include<stdio.h>
char * MyStrNSet(char *, char, int);
int main(void)
{
	int iNo;
	char chChar;
	char szStr[20];

	printf("\nEnter the string :- ");			//Enter the string :- tanay dherange
	gets(szStr);
	printf("\nEnter the character to set :- ");	//Enter the character to set :- *
	scanf("%c",&chChar);
	printf("\nEnter the no. of characters to set :- "); 	//Enter the no. of characters to set :- 7
	scanf("%d",&iNo);

	MyStrNSet(szStr,chChar,iNo);

	printf("\nNow string is : ");				//Now string is : *******
	puts(szStr);

	return 0;
}
char * MyStrNSet(char *pszStr, char chChar, int iNo)
{
	int iCounter;
	for(iCounter = 0; *pszStr != '\0' && iCounter<iNo; iCounter++,pszStr++)
		*pszStr = chChar;
	*pszStr = '\0';

	return pszStr-iCounter;
}