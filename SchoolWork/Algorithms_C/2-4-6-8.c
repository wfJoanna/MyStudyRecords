#include <stdio.h>
int main()
{
    int n, m;
    double s = 0.0;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        s += (double)1 / i / i;
    }
    printf("%.5lf\n", s);
    return 0;
}
