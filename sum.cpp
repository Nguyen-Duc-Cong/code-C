#include<stdio.h>
#define ENTER 10
int main()
{
	int noD = 0 ,noL = 0,noO = 0;
	//noD = noL= noO = 0;
	char c;
	printf("Enter a string\n");
	while(c != ENTER)
	{
		c = getchar();
		if(c >= '0' && c <= '9')		noD++;
		else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				noL++; 
			else noO++;


	}
	printf("noDigits: %d noLetters: %d noOthers: %d",noD,noL,noO-1);
	return 0;
	
}
