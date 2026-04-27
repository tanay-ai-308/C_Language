#include<stdio.h>
char * MyStrLwr (char *);
int main(viod)
{
	char szStr[20];

	printf("\n-----------String will be converted to lowercase.-----------\n");
	printf("\nEnter the string :- \n\t");			//Enter the string :- tAnAy DHERAnge
	gets(szStr);

	MyStrLwr(szStr);

	printf("\n\nConverted string is :- \n\t");		//Converted string is :- 
	puts(szStr);									//        tanay dherange

	return 0;
}
char * MyStrLwr (char *pszStr)
{
	int iCounter = 0;

	for(iCounter = 0; *pszStr != '\0'; iCounter++, pszStr++)
	{
		if(*pszStr >= 'A' && *pszStr <= 'Z')
			*pszStr=*pszStr+32;
	}

	return pszStr-iCounter;
}