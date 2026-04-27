#include<stdio.h>
char * MyStrNCat(char *,const char *,int);
int main(void)
{
	int iNo;
	//char * chAddress = NULL;
	char chSource[20];
	char chDestination[20];

	printf("\nEnter Source string :-\n\t\t");			//Enter Source string :-
	gets(chSource);										//                Dherange

	printf("Enter Destination string :- \n\t\t");		//Enter Destination string :-
	gets(chDestination);								//                Tanay	

	//printf("\naddress of chDestination is %d.",chDestination);
	
	printf("\nEnter the value of 'n' - ");				//Enter the value of 'n' - 5
	scanf("%d",&iNo);							

	MyStrNCat(chDestination,chSource,iNo);
	//chAddress = MyStrNCat(chDestination,chSource,iNo);
	//printf("\naddress in chAddress is %d.",chAddress);

	printf("\nConcatenated string is :-\n\t\t");		//Concatenated string is :-
	puts(chDestination);								//                Tanay Dhera

	return 0;
}
char * MyStrNCat(char *pchDestination,const char *pchSource,int iNo)
{
	int iLen = 0;
	int iCounter = 0;

	while (*pchDestination != '\0')
	{
		iLen++;
		*pchDestination++;
	}

	while (*pchSource != '\0' && iCounter < iNo)
	{
		*pchDestination = *pchSource;
		pchDestination++;
		pchSource++;
		iCounter++;
	}
	
	//for (iLen=0,iCounter=0 ; *pchSource != '\0' && iCounter < iNo ; pchDestination++,pchSource++,iCounter++)
	//	*pchDestination = *pchSource;
	*pchDestination ='\0';

	return (pchDestination-(iLen+iCounter));
}