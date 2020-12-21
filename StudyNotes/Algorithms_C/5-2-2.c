#include <stdio.h>
#define MAX 3000

int main()
{
    int n, i, j;
    scanf("%d", &n);

    int f[MAX] = {0};
    f[0] = 1;
    for (i = 2; i <= n; i++)
    {
        int c = 0; //进位
        for (j = 0; j < MAX; j++)
        {
            int s = f[j] * i + c;
            f[j] = s % 10; //本位
            c = s / 10;
        }
    }

    for (i = MAX - 1; i >= 0; i--)
        if (f[i])
            break;
    for (j = i; j >= 0; j--)
        printf("%d", f[j]);
    printf("\n");
    return 0;
}