#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%.*lf\n", c, (double)a / b); //为啥先把a变成double且只需把a变成double，不用我写了吧
    //该定义浮点数输出的小数位数的地方，放了*星号，则由后面的第一个变量代替他
    return 0;
}
