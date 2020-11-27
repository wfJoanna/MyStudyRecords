#include <stdio.h>
int main()
{
	float a,b;
	printf("Enter value of trade: ");
	scanf("%f",&a);
	
	while(a!=0){
		if(a<2500){
          b=30+0.017*a;
          if(b<39) printf("Commission: $39.00\n\n");
          else printf("Commission: $%.2f\n\n",b);}
	    else if(a>=2500&&a<=6250){
	      b=56+0.0066*a;
	      printf("Commission: $%.2f\n\n",b);}
        else if(a>=6450&&a<=20000){
          b=76+0.0034*a;
          printf("Commission: $%.2f\n\n",b);}
        else if(a>=20000&&a<=50000){
          b=100+0.0022*a;
          printf("Commission: $%.2f\n\n",b);}
        else if(a>=50000&&a<=500000){
          b=155+0.0011*a;
          printf("Commission: $%.2f\n\n",b);}
        else if(a>=500000){
          b=255+0.0009*a;
          printf("Commission: $%.2f\n\n",b);}
        
		printf("Enter value of trade: ");
	    scanf("%f",&a);
	}
	return 0;
}
