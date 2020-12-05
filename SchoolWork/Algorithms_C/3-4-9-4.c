#include <stdio.h>
#include <string.h>
#define MAX 20
int main()
{
    char s[MAX], s2[MAX];
    fgets(s, sizeof(s), stdin);
    int mark1 = 0, mark2, a = 0, b = 0, j = 0; //mark2标志是哪个运算符，a表示第一个数，b表示第二个数

    for (int i = 0; i < strlen(s); i++) //把空格全去掉
    {
        if (s[i] != ' ')
        {
            s2[j++] = s[i];
        }
    }

    for (int i = 0; i < strlen(s2); i++)
    {
        if (s2[i] == '+')
        {
            mark2 = 1;
            mark1 = 2;
        }
        else if (s2[i] == '-')
        {
            mark2 = 2;
            mark1 = 2;
        }
        else if (s2[i] == '*')
        {
            mark2 = 3;
            mark1 = 2;
        }
        else if (s2[i] >= '0' && s2[i] <= '9')
        {
            if (mark1 == 0)
            {
                a = s2[i] - '0';
                mark1 = 1;
            }
            else if (mark1 == 1)
                a = a * 10 + (s2[i] - '0');
            else if (mark1 == 2)
            {
                b = s2[i] - '0';
                mark1 = 3;
            }
            else if (mark1 == 3)
                b = b * 10 + (s2[i] - '0');
        }
    }
    if (mark2 == 1)
        printf("%d\n", a + b);
    else if (mark2 == 2)
        printf("%d\n", a - b);
    else if (mark2 == 3)
        printf("%d\n", a * b);
    return 0;
}