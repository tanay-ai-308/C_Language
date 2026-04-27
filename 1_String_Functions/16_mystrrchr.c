#include<stdio.h>
char * MyStrRchr(const char *,char);

int main(void)
{
	char szStr[30];
	char chChar;
	char *pPtr;

	printf("\nEnter the string :- ");				//Enter the string :- tanay
	gets(szStr);
	printf("\nEnter character to be found : ");		//Enter character to be found : a
	scanf("%c",&chChar);

	pPtr=MyStrRchr(szStr,chChar);

	if(NULL==pPtr)
		printf("\nCharacter is not found.");
	else
		printf("\nCharacter is found at %d location.",(pPtr-szStr)+1);		//Character is found at 4 location.

	return 0;
}
char * MyStrRchr(const char *pszStr,char chChar)
{	
	char *pPtr = NULL;
	while(*pszStr != '\0')
	{
		if(*pszStr == chChar)
			pPtr = (char *) pszStr;
		pszStr++;
	}
	return pPtr;
}