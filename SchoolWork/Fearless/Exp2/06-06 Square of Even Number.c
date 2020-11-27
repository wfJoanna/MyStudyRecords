#include <stdio.h>
int main()
{
	int n,x,a;
	
	printf("Enter a number: ");
	scanf("%d",&n);
	
	a=2;
	x=a*a;
	while(x<=n){
		printf("%d\n",x);
		a=a+2;
		x=a*a;
	}
	return 0;
}
