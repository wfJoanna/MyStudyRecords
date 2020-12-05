#include <stdio.h>
int main()
{
	int n,a,b,c,d;
	
	printf("Enter a dollar amount: ");
	scanf("%d",&n);
	
	a=n/20;
	b=n%20/10;
	c=n%20%10/5;
	d=n-20*a-10*b-5*c;
	
	printf("\n");
	printf("$20 bills: %d\n",a);
	printf("$10 bills: %d\n",b);
	printf(" $5 bills: %d\n",c);
	printf(" $1 bills: %d\n",d);
	
	return 0;
}
