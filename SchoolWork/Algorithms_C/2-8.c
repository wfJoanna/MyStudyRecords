#include <stdio.h>
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout); //输入输出重定向
    int x, n = 0, min, max, s = 0;

    scanf("%d", &x);
    n++;
    s += x;
    min = max = x; //可以连续赋值，但仅限已经定义过的变量
    
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