#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char s[MAX];
    scanf("%s", s); //注意，遇空格或回车就停止读入了哦，所以字符串要相连

    int len = strlen(s); //这里的len不包含'\n'哦，scanf()不读入'\n'，不像fgets()
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