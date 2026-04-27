#include<stdio.h>
char * MyStrSet(char *, char);
int main(void)
{
	char szStr[20];
	char chChar;

	printf("\nEnter the string :- ");			//Enter the string :- tanay
	gets(szStr);
	printf("\nEnter the character to set :- ");	//Enter the character to set :- *
	scanf("%c",&chChar);

	MyStrSet(szStr,chChar);

	printf("\nNow string is : ");				//Now string is : *****
	puts(szStr);

	return 0;
}
char * MyStrSet(char *pszStr, char chChar)
{
	int iCounter;
	for(iCounter = 0; *pszStr != '\0'; iCounter++,pszStr++)
		*pszStr = chChar;
	*pszStr = '\0';

	return pszStr-iCounter;
}