#include<stdio.h>
int main()
{
	int n;
	double x,y;
	printf("enter an integer:");
	scanf("%d",&n);
	printf("\nenter 2 real nnumber:");
	scanf("%lf%lf",&x,&y);
	double num1,num2;
	char op;
	printf("enter an expression +-*/ :");
	scanf("%lf%c%lf",&num1,&op,&num2);
	printf("Expression inputted is: %.2lf%c%.2lf",num1,op,num2);
	return 0;
}
