#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d", &n);
    m = 100 * (n % 10) + 10 * (n / 10 % 10) + 1 * (n / 100);
    printf("%d\n", m); //���Ҫ�����λ��0������printf("%03d\n", m);
    return 0;
}
