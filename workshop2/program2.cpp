#include<stdio.h>
#define pa 9000000
#define pd 3600000
int main()
{


	int in,ti,tf;
	int n;
	
	printf("Your income of this year: ");
	scanf("%d",&in);
	printf("Number of dependent: ");
	scanf("%d",&n);
	tf = 12*(pa+n*pd);
	printf("Tax-free income: %d",tf);
	ti = in - tf;
	int it;
	if (ti <= 0){
		ti = 0;
	}
	else if(0 < ti && ti <= 5000000)	it = ti*0.05;	
	else if(ti <= 10000000) it = 250000+(ti-5000000)*0.1;
	else if(ti <= 18000000) it = 750000+ (ti-10000000)*0.15;
	else it = 1950000+(ti-18000000)*0.2;
	printf("\nTaxable income: %d",ti);
	if (ti != 0)printf("\nIncome tax: %d",it);
	
	return 0;
}
