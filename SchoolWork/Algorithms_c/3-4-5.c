#include <stdio.h>
#include <string.h>
#define MAX 10000000
char s[MAX]; //��֪��Ϊɶ������ַ��������������main�������û�취���У����Ƿ���main������Ϳ��ԡ��ٶ���ȫ�Ѳ����������ٶ�

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