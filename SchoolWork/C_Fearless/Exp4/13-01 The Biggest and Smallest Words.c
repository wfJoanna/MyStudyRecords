#include<stdio.h>
#include<string.h>

int main()
{
	char words[30][21],word[21];
	int i=0,j,row=0;
	
	void read_line(char str[]);
	
	while(1){
		printf("Enter word: ");
		read_line(word);
		i=0;
		if(row==0)goto done;
		while(i<row){
			if(strcmp(word,words[i])<0) break;
			i++;}
		j=row;
		while(j>i){
		    strcpy(words[j],words[j-1]);
		    j--;}
        done:
		strcpy(words[i],word);
		row++;	
		if(word[4]=='\0'&&word[3]!='\0')break;	
	}
	printf("\n");
	printf("Smallest word: %s\n",words[0]);
	printf("Largest word: %s\n",words[row-1]);
	
	return 0;
}

void read_line(char str[])
{
	int ch,i=0;
	
	while(1){
	  ch=getchar();
	  if((ch=='\n'&&i==0)||(ch=='\0'&&i==0))continue;
	  else if(ch=='\n'&&i!=0)break;
	  else str[i++]=ch;}
    str[i]='\0';
}
