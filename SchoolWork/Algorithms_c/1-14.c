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
    } //��Ϊ���������֮��a��ֵ�����ܱ�����������a>b����Ȼ��������������ֻ��Ҫ�Ƚ�b��c��
    //��Ҳ˵���ˣ����˳�򲻶ԣ��Ϳ��ܳ���Ŷ
    //������a>b,b>c,a>c��˳��
    //�����b>c���������b��ø�С�ˣ��Ϳ���ǰ��õ���a<b�Ͳ�������
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}