#include <stdio.h>
int main()
{
	int digit,digit_seen[10]={0};
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	if(n==0) digit_seen[0]=1;
    while(n>0){
		digit=n%10;
		digit_seen[digit]++;
		n/=10;
	  }
	
	printf("Digit:		0  1  2  3  4  5  6  7  8  9\n");
	printf("Occurrences:	%d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n",digit_seen[0],digit_seen[1],digit_seen[2],digit_seen[3],digit_seen[4],digit_seen[5],digit_seen[6],digit_seen[7],digit_seen[8],digit_seen[9]);
    return 0;
}
