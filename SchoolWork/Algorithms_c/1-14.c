#include <stdio.h>
int main()
{
    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    if (a > c)
    {
        t = a;
        a = c;
        c = t;
    } //因为经历了这个之后，a的值不可能变大，所以上面的a>b还仍然成立，所以下面只需要比较b和c了
    //这也说明了，如果顺序不对，就可能出错哦
    //比如以a>b,b>c,a>c的顺序
    //如果在b>c这个环节中b变得更小了，就可能前面得到的a<b就不成立了
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}