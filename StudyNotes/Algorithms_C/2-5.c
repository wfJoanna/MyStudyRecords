#include <stdio.h>
int main()
{
    int n, S;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int factorial = 1;
        for (int j = 1; j <= i; j++)
            factorial *= j;
        S += factorial;
    }
    printf("%d\n", S % 1000000);
}