#include <stdio.h>
#include <string.h>
#define MAX 10

int main()
{
    int number = 0, mark = 0, s = 1;
    char n;
    char s2[MAX];
    while ((n = getchar()) != '\n')
    {
        if (n >= '0' && n <= '9')
        {
            if (mark)
                number = number * 10 + (n - '0');
            else
            {
                number = n - '0';
                mark = 1;
            }
        }
        else
        {
            if (mark)
            {
                s *= number;
                number = 0;
                mark = 0;
            }
        }
    }
    if (mark)
    {
        s *= number;
        number = 0;
        mark = 0;
    }

    sprintf(s2, "%d", s); //用这种方法把数字转换成字符串
    int i = strlen(s2);
    if (i > 3)
        printf("%c%c%c\n", s2[i - 3], s2[i - 2], s2[i - 1]);
    else
        printf("%d", s);
    return 0;
}