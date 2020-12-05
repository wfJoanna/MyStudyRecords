#include<stdio.h>
int main()
{
	int n,x,num,i,j;
	char word[80]={'\0'},
	     letter1[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
         letter2[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	printf("Enter message to be encrypted: ");
	for(x=0;;x++){
	   word[x]=getchar();
	   if(word[x]=='\n') break;
	}
	
	printf("Enter shift amount (1-25): ");
	scanf("%d",&num);
	for(i=0;;i++){
		if(word[i]>64&&word[i]<91) {
		   for(j=0;;j++)if(((word[i] - 'A') + num) % 26 + 'A'==letter1[j])break;
		   word[i]=letter1[j];}
  
        else if(word[i]>96&&word[i]<123){
		        for(j=0;;j++)if(((word[i] - 'a') + num) % 26 + 'a'==letter2[j])break;
		        word[i]=letter2[j];} 
		        
        if(word[i+1]=='\0')break;
		        
	}
	
	printf("Encrypted message: ");
	x=0;
	while(word[x]!='\0'){
		printf("%c",word[x]);
		x++;
	}
	return 0;
}
