#include <stdio.h>
int main()
{
    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    //rb,wb和r,w的区别就是，末尾的b表示二进制。以二进制形式和以文本形式读写的区别，有点复杂，反正大概就是关于转义字符怎么读怎么写
    //一般只需要记住，rb,wb读写的是二进制文件(通常后缀名.dat),r,w读写的是文本(通常是后缀名.txt记事本)
    int x, n = 0, max, min, s = 0;

    fscanf(fin, "%d", &x);
    n++;
    s += x;
    max = min = x;

    while (fscanf(fin, "%d", &x) == 1)
    {
        n++;
        s += x;
        if (max < x)
            max = x;
        if (min > x)
            min = x;
    }

    fprintf(fout, "%d %d %.3lf\n", min, max, (double)s / n);
    
    fclose(fin);
    fclose(fout);
    return 0;
}