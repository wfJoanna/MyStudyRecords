#include <stdio.h>
int main()
{
	int m,w,i=1;
	printf("Enter number of days in month: ");
	scanf("%d",&m);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d",&w);
	printf("\n");
	if(i<w)
	  printf("  ");
    for(i=2;i<w;i++)
      printf("   "); 
    for(i=1;i<=m;i++){	
      if((i+w-1)%7==1) printf("%2d",i);
      else printf("%3d",i);
	  if((i+w-1)%7==0||i==m) 
	    printf("\n");
	  }
	return 0;
}

/*不得不说这一个是我做的最烦躁的一个，因为那个在线测试在检测这一个的时候，
是最最最最死板的时候！！！！！！我去你大爷！！！！明明我那个写法也是对的
啊，结果和这个完全一毛一样啊，这个你给100分，我那个就给二十几分，你脑子
瓦特啦！！！！！！！！*/ 