#include<stdio.h>
char *MyStrCpy(char *,const char *);
int main(void)
{
	char chSource[20];
	char chDestination[20];

	printf("\nEnter Source string :-\n\t\t");		//Enter Source string :-
	gets(chSource);									//                My name is tanay suresh dherange and I am in 1st year of BSC(CS).

	printf("Source string is :- \n\t\t");			//Source string is :-
	puts(chSource);									//                My name is tanay suresh dherange and I am in 1st year of BSC(CS).

	MyStrCpy(chDestination,chSource);

	printf("\nDestination string is :-\n\t\t");		//Destination string is :-
	puts(chDestination);							//                My name is tanay suresh dherange and I am in 1st year of BSC(CS).

	return 0;
}
char *MyStrCpy(char *pchDestination,const char *pchSource)
{
	for( ; (*pchSource) != '\0'; pchSource++,pchDestination++)
		*pchDestination = *pchSource;
	*pchDestination='\0';

	return (pchDestination-iCounter);
}