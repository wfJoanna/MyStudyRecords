#include <stdio.h>
int main()
{
	int a,b,c;
	
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &a,&b,&c);
	
	printf("You entered the date %4.4d%2.2d%2.2d\n", c,a,b);
 
    return 0;
}
