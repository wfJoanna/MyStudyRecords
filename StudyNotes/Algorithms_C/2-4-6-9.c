#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%.*lf\n", c, (double)a / b); //Ϊɶ�Ȱ�a���double��ֻ���a���double��������д�˰�
    //�ö��帡���������С��λ���ĵط�������*�Ǻţ����ɺ���ĵ�һ������������
    return 0;
}
