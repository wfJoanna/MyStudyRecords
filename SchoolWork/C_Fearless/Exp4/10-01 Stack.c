#include<stdio.h>

char contents[100];
int top=0;

int main()
{
	void push(char);
	char pop(void),ch1,ch2;
	printf("Enter parentheses and/or braces: ");
	while(1){
		ch1=getchar(); 
		if(ch1==')'){
			ch2=pop();
			if(ch2=='(')continue;
			else break;
		}
		else if(ch1=='}'){
			ch2=pop();
			if(ch2=='{')continue;
			else break;
		}
		else if(ch1=='\n') break;
		push(ch1);
		
	}
	
	if(top==0) printf("Parentheses/braces are nested properly\n");
	else printf("Parentheses/braces are NOT nested properly\n");
	
	return 0;
}

void push(char ch)
{
	contents[top++]=ch;
}

char pop(void)
{
	return contents[--top];
}
