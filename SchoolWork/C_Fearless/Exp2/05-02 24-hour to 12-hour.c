#include <stdio.h>
int main()
{
	int a,b,c;
	printf("Enter a 24-hour time: ");
	scanf("%d:%1d%1d",&a,&b,&c);
	
	printf("Equivalent 12-hour time: ");
	
	if(a<12){
		if(a==0)
		  printf("12:%d%d AM\n",b,c);
        else
	      printf("%d:%d%d AM\n",a,b,c);     
	}
    else if(a==12)
	  printf("12:%d%d PM\n",b,c);
	else if(a>12)
	  printf("%d:%d%d PM\n",a-12,b,c);
	  
    return 0;
}
