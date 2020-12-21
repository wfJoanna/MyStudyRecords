#include <stdio.h>
#include <time.h>
int main()
{
    int n, S;
    const int MOD = 1000000;
    scanf("%d", &n);
    if (n > 25)
        n = 25;
    for (int i = 1; i <= n; i++)
    {
        int factorial = 1;
        for (int j = 1; j <= i; j++)
            factorial = factorial * j % MOD;
        S = (S + factorial) % MOD;
    }
    printf("%d\n", S);
    printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC);
}