#include <stdio.h>
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout); //��������ض���
    int x, n = 0, min, max, s = 0;

    scanf("%d", &x);
    n++;
    s += x;
    min = max = x; //����������ֵ���������Ѿ�������ı���
    
    while (scanf("%d", &x) == 1)
    {
        n++;
        s += x;
        if (max < x)
            max = x;
        if (min > x)
            min = x;
    }
    printf("%d %d %.3lf\n", min, max, (double)s / n);
    return 0;
}