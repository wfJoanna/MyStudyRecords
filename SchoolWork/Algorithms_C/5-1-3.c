#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char s[MAX];
    scanf("%s", s); //ע�⣬���ո��س���ֹͣ������Ŷ�������ַ���Ҫ����

    int len = strlen(s); //�����len������'\n'Ŷ��scanf()������'\n'������fgets()
    for (int i = 1; i <= len; i++)
    {
        if (len % i == 0)
        {
            int ok = 1;
            for (int j = i; j < len; j++)
            {
                if (s[j] != s[j % i])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}