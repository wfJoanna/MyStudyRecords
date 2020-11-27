#include <stdio.h>
int main()
{
	int a,b,m,n,x;
	printf("Enter two integers: ");
	scanf("%d %d",&a,&b);
	
	if(a>b) m=a,n=b;
	else m=b,n=a;
	
	while(n!=0){
		x=m%n;
		m=n;
		n=x;
	}
	
	printf("Greatest common divisor: %d\n",m);

    return 0;
}
