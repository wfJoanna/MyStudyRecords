#include <stdio.h>

int is_prime(int x) //�����д�����������������4-2��Ӧ�����Ҫ�󣬶����������ж���������
{
    for (int i = 2; i * i <= x; i++) //ע���������������ö�ٵ�i=x��ֻ��Ҫö�ٵ�i*i<=x�ĳ̶ȾͿ�����
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int m;
    scanf("%d", &m);
    for (int n = m; n - 2 >= 1; n--)
    {
        if (is_prime(n) && is_prime(n - 2))
        {
            printf("%d %d\n", n - 2, n);
            return 0;
        }
    }
}
