#include<stdio.h>
int main()
{
	double num1,num2;
	char op;
	scanf("%lf%c%lf",num1,op,&num2);
	//scanf("%c",&op);
	printf("%lf%c%lf=",num1,op,num2);

	switch (op)
	{
		case'+':
			{
			printf("%.4lf",num1+num2);
				break;
			}
		case'-':
		{
			printf("%.4lf",num1-num2);
			break;
		}
		case'*':
		{
			printf("%.4lf",num1*num2);
			break;
		}
		case'/':
		{if ( num2==0)
    	printf("Divide by 0 ");
            else printf("%.4lf",num1/num2);
			break;
		}
		default: printf("Op is not supported");
	}
	//return 0;
}
