#include <stdio.h>
int main()
{
    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    //rb,wb��r,w��������ǣ�ĩβ��b��ʾ�����ơ��Զ�������ʽ�����ı���ʽ��д�������е㸴�ӣ�������ž��ǹ���ת���ַ���ô����ôд
    //һ��ֻ��Ҫ��ס��rb,wb��д���Ƕ������ļ�(ͨ����׺��.dat),r,w��д�����ı�(ͨ���Ǻ�׺��.txt���±�)
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