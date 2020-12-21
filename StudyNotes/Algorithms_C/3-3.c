#include <stdio.h>
#define MAX 10
int main()
{
    int n;
    scanf("%d", &n);
    int a[MAX][MAX] = {0};

    /*1.这是我自己想的
    int x = 0, y = n - 1, item = 1;
    for (int i = 0; i < n - 1; i++)
    {
        while (x < n - 1 - i)
            a[x++][y] = item++;
        while (y > i)
            a[x][y--] = item++;
        while (x > i)
            a[x--][y] = item++;
        while (y < n - 2 - i)
            a[x][y++] = item++;
    }
    a[x][y] = n * n;
    */

    /*2.书上的方法，其实没有太大区别*/
    int x = 0, y = n - 1, item = 1;
    a[x][y] = item;
    while (item < n * n)
    {
        while (x + 1 <= n - 1 && !a[x + 1][y])
            a[++x][y] = ++item;
        while (y - 1 >= 0 && !a[x][y - 1])
            a[x][--y] = ++item;
        while (x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = ++item;
        while (y + 1 <= n - 2 && !a[x][y + 1])
            a[x][++y] = ++item;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}