﻿#include <stdio.h>
int main()
{
	int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,first_sum,second_sum,total,m;
	
	printf("Enter the first (single) digit: ");
	scanf("%1d",&d);
	printf("Enter first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5);
	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d",&j1,&j2,&j3,&j4,&j5);
	printf("Enter the last (single) digit: ");
	scanf("%d",&m);
	
	first_sum=d+i2+i4+j1+j3+j5;
	second_sum=i1+i3+i5+j2+j4;
	total=9-(3*first_sum+second_sum-1)%10;
	
	if(total==m)
	  printf("VALID\n");
    else
      printf("NOT VALID\n");
      
    return 0;
}