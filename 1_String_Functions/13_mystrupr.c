#include<stdio.h>
char * MyStrUpr (char *);
int main(viod)
{
	char szStr[20];

	printf("\n-----------String will be converted to Uppercase.-----------\n");
	printf("\nEnter the string :- \n\t");			//Enter the string :- tAnAy DHERAnge
	gets(szStr);

	MyStrUpr(szStr);

	printf("\n\nConverted string is :- \n\t");		//Converted string is :- 
	puts(szStr);									//        tanay dherange

	return 0;
}
char * MyStrUpr (char *pszStr)
{
	int iCounter = 0;

	for(iCounter = 0; *pszStr != '\0'; iCounter++, pszStr++)
	{
		if(*pszStr >= 'a' && *pszStr <= 'z')
			*pszStr=*pszStr-32;
	}

	return pszStr-iCounter;
}