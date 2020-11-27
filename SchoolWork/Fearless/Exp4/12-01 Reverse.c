#include <stdio.h>
int main()
{
	char ch,word[50];
	int i;
	printf("Enter a message: ");
	for(i=0;;i++){
		word[i]=getchar();
		if(word[i]=='\n')break;
	}
	printf("Reversal is: ");
	for(;i>0;i--){
		printf("%c",word[i-1]);
	}
	printf("\n");
	return 0;
}
