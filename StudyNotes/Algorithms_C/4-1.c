#include <stdio.h>

long long f(long long);

int main()
{
    long long n, m; //��Ϊ��Ŀ�趨n���Ϊ20��������long long�պá��������20���Ϳ�����long longҲ������ˣ���ʱ����Ҫ���������ˣ����Ǻ��鷳
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