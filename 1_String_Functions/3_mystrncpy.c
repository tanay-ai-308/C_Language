#include<stdio.h>

char *MyStrCpy(char *,const char *,int);

int main(void)
{
	int iNo;
	//char *chAddress = NULL;
	char chSource[20];
	char chDestination[20];

	//printf("\naddress in chDestination = %d",chDestination);

	printf("\nEnter Source string :-\n\t\t");		//Enter Source string :-	
	gets(chSource);									//                my name is tanay

	printf("Enter the value of 'n' - ");			//Enter the value of 'n' - 2
	scanf("%d",&iNo);

	printf("Source string is :- \n\t\t");			//Source string is :-
	puts(chSource);									//                my name is tanay

	MyStrCpy(chDestination,chSource,iNo);
	//chAddress = MyStrCpy(chDestination,chSource,iNo);
	//printf("\naddress in chDestination = %d",chAddress);

	printf("\nDestination string is :-\n\t\t");		//Destination string is :-	
	puts(chDestination);							//                my

	return 0;
}
char *MyStrCpy(char *pchDestination,const char *pchSource,int iNo)
{
	int iCounter;

	for( iCounter = 0; iCounter < iNo; pchSource++,pchDestination++,iCounter++)
		*pchDestination = *pchSource;
	*pchDestination='\0';

	return (pchDestination-iCounter);
}