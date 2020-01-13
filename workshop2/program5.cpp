#include<stdio.h>
#include<ctype.h>
int main()
{
	int nVowels = 0,nConsonants = 0,nOthers = 0;
	char ch;
   	do {
 	ch = getchar();
 	ch= toupper(ch);
	if ( ch>='A' && ch <='Z') {
    switch (ch) {
        case 'A' :
        case 'E' :
        case 'I' :
        case 'O' :
        case 'U' : 
		{
		 	nVowels ++; 
			break;
		}
         default:  nConsonants++;
     }
	}
	else nOthers++;
    }
    while ( ch != '\n');
    printf("\nprint out nVowels: %d", nVowels);
    printf("\nprint out nConsonants: %d", nConsonants);
    printf("\nPrint out nOthers: %d", nOthers-1);

	//return 0;
}
