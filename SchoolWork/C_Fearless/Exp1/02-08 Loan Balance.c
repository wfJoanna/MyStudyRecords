#include <stdio.h>
int main()
{
	float a,b,c,n1,n2,n3,x;
	
	printf("Enter amount of loan: ");
	scanf("%f", &a);
	printf("Enter interest rate: ");
	scanf("%f", &b);
	printf("Enter monthly payment: ");
	scanf("%f", &c);
	
	x=b/100/12;
	n1=a*(1+x)-c;
	n2=n1*(1+x)-c;
	n3=n2*(1+x)-c;
	
	printf("\n");
	printf("Balance remaining after first payment: $%.2f\n",n1);
	printf("Balance remaining after second payment: $%.2f\n",n2);
	printf("Balance remaining after third payment: $%.2f\n",n3);
	
	return 0;
}
