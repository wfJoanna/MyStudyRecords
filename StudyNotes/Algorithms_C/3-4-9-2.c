#include <stdio.h>
#define MAX 100

int main()
{
    char s[MAX];
    char n;
    int i = 0, count = 0, sig = 0;
    while (1)
    {
        scanf("%c", &n);
        if (n == '\n')
        {
            if (sig)
                count++;
            break;
        }
        else if (n == ' ')
        {
            if (sig)
            {
                count++;
                sig = 0;
            }
        }
        else
        {
            s[i++] = n;
            if (!sig)
                sig = 1;
        }
    }
    printf("%d\n", i / count);
    return 0;
}