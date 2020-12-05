#include <stdio.h>
int main()
{
	int n,a;
	printf("Enter numerical grade: ");
	scanf("%d",&n);
	
	if(n<0||n>100)
	  printf("Error, grade must be between 0 and 100.\n");
    else {
    	a=(n-n%10)/10;
    	printf("Letter Grade: ");
    	switch(a){
	    	case 9: printf("A\n");break;
	    	case 8: printf("B\n");break;
	    	case 7: printf("C\n");break;
	    	case 6: printf("D\n");break;
	    	case 0:case 1:case 2:case 3:case 4:case 5:case 10:
	    		if(n==100) 
				  printf("A\n");
	    		else 
				  printf("F\n"); 
	    	break;
    	};
    };
   return 0;
}
