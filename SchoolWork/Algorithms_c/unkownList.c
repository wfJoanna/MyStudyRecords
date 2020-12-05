/*此文件用来记录一种情况的解决方法：不知道数组大小，但是要初始化数组*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *a;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * (n + 1)); //这样之后，就可以像使用普通数组一样使用a啦。注意要添加头文件

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
