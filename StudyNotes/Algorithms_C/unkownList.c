/*���ļ�������¼һ������Ľ����������֪�������С������Ҫ��ʼ������*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *a;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * (n + 1)); //����֮�󣬾Ϳ�����ʹ����ͨ����һ��ʹ��a����ע��Ҫ���ͷ�ļ�

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
