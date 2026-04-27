#include<stdio.h>
char * MyStrCat(char *,const char *);
int main(void)
{
	char *chAddress = NULL;
	char chSource[20];
	char chDestination[20];

	printf("\nEnter Source string :-\n\t\t");			//Enter Source string :-
	gets(chSource);										//                Dherange

	printf("Enter Destination string :- \n\t\t");		//Enter Destination string :-
	gets(chDestination);								//                Tanay	
	printf("\naddress in chDestination = %d",chDestination);

	chAddress = MyStrCat(chDestination,chSource);
	printf("\naddress in chAddress = %d",chAddress);

	printf("\nConcatenated string is :-\n\t\t");		//Concatenated string is :-
	puts(chDestination);								//                Tanay Dherange

	return 0;
}
char * MyStrCat(char *pchDestination,const char *pchSource)
{
	int iLen = 0;

	while (*pchDestination != '\0')
	{
		iLen++;
		*pchDestination++;
	}

	while (*pchSource!='\0')
	{
		*pchDestination = *pchSource;
		pchDestination++;
		pchSource++;
		iLen++;
	}
	*pchDestination ='\0';

	return (pchDestination-iLen);
}