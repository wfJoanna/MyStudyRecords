#include <stdio.h>
#include <string.h>
#define MAX 10000000
char s[MAX]; //不知道为啥，这个字符串声明如果放在main函数里，就没办法运行，但是放在main函数外就可以。百度完全搜不到，垃圾百度

int main()
{
    int tot = 0;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == '1')
            tot++;
    printf("There are %d character(s) '1' in the string.\n", tot);
    return 0;
}