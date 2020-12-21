/*其实应该是2.4.4.1.cpp，但是这样的文件名没法编译运行
是第二章小结与习题的2.4.4的第一种方法
总之就说一下，后面我就不说了*/
#include <cstdio>
using namespace std;
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2)
        printf("%d\n", a + b);
    return 0;
}