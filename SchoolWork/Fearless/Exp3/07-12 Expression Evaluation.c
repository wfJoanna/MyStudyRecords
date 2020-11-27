#include <stdio.h>
int main()
{
	float a[100],W,ch,b[100];
	int x=0,i,n;
	
	printf("Enter an expression: ");
	
	for(;;){
	  if(x%2==0){scanf("%f",&ch);a[x]=ch;x++;}
  	  else {ch=getchar();
		    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){b[x]=ch;x++;}
	        else if(ch=='\n') break;}
	}
	
	x=0;
	W=a[0];
	
	do{
	  if(b[x+1]=='+') W+=a[x+2];
	  else if(b[x+1]=='-') W-=a[x+2];
	  else if(b[x+1]=='*') W*=a[x+2];
	  else if(b[x+1]=='/') W/=a[x+2];
	  x+=2;	
	  }while(b[x-1]!=0);
	
	if(W-(int)W==0) n=0;
	else{
      for(i=1;;i++){
	    if(i*10*W-(int)i*10*W==0) n=i;break;
        }
	}
	
	if(n==0) printf("Value of expression: %.0f\n",W);
	else if(n==1) printf("Value of expression: %.1f\n",W);
	else if(n==2) printf("Value of expression: %.2f\n",W);
	
	return 0;
}
