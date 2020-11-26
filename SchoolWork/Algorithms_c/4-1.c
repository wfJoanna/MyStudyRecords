#include <stdio.h>

long long f(long long);

int main()
{
    long long n, m; //因为题目设定n最大为20，所以用long long刚好。如果超过20，就可能连long long也会溢出了，这时就需要数组来存了，但是好麻烦
    scanf("%d%d", &n, &m);
    printf("%d\n", f(n) / (f(m) * f(n - m)));
    return 0;
}

long long f(long long i)
{
    long long j, x = 1;
    for (j = 1; j <= i; j++)
        x = x * j;
    return x;
}