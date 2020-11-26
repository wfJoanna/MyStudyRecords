#include <stdio.h>
int main()
{
    int count[101] = {0};
    int n, max = 0;
    char m;
    while (scanf("%d%c", &n, &m)) //当不确定输入的数字个数时，就可以用这招啦（注意要配合循环体里的m=='\n'）
    {
        count[n]++;
        if (m == '\n')
            break;
    }

    for (int i = 0; i <= 100; i++)
        if (count[i] > max)
            max = count[i];

    for (int i = 0; i <= 100; i++)
        if (count[i] == max)
            printf("%d\n", i);

    return 0;
}