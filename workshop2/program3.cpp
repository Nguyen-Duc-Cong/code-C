#include<stdio.h>

int main()
{
	int x,S = 0 ;
   	do 
   	{
       	 scanf("%d",&x);
       	 if (x != 0) S = S + x; 
   	}
   while  (x!=0);
	printf("Sum: %d",S);
	return 0;
}
