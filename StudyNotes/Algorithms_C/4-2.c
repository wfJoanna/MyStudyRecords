#include <stdio.h>

int is_prime(int x) //这儿编写的这个函数仅适用于4-2对应的题的要求，而不适用于判断所有素数
{
    for (int i = 2; i * i <= x; i++) //注意啦，你这儿不用枚举到i=x，只需要枚举到i*i<=x的程度就可以了
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
