#include<stdio.h>

int main()
{
	char c1,c2;
	int d;
	char t,c;
	scanf("%c",&c1);
	fflush(stdin);
	scanf("%c",&c2);
     if (c1 > c2 ) 
     { 	t = c1; 
	   	c1 = c2;
		c2= t;
     }
     d = c2 - c1; 
     printf("Print out d: %d", d);
     for(c = c1; c <= c2; c++)
		printf("\n%c: %d, %o, %X", c, c, c, c);
	return 0;
}
