#include<stdio.h>

int MyStrLen(const char*);

int main (void)
{
	char *pPtr = "Hello";
	char chStr[] = "Good";

	printf("\n1] The length of pPtr[Hello] is = %d.",MyStrLen(pPtr));			//1] The length of pPtr[Hello] is = 5.
	printf("\n2] The length of chStr[Good] is = %d.",MyStrLen(chStr));			//2] The length of chStr[Good] is = 4.
	printf("\n3] The length of [Morning] is = %d.",MyStrLen("Morning"));		//3] The length of [Morning] is = 7.

	return 0;
}
int MyStrLen(const char* pchChar)
{
	int iLength;
	
	for(iLength = 0;(*pchChar)!='\0'; pchChar++,iLength++);

	return iLength;
}