#include <stdio.h>
int main()
{
    char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; //ע��������'\\'������'\'
    //֮ǰ������ֱ��s[MAX]="xxxxx"����ȻҲ��������������ֱ����ָ�룬������ʵ����ָ���һ��

    int i, c;                      //�ַ�����ֱ������Ϊint��������������putchar()�����Զ�ת��Ϊ�ַ������
    while ((c = getchar()) != EOF) //EOF��ʾend of file��һ����getchar()ѭ����ȡʱ������������ʽ��ֹͣѭ��������ʵ����ֹͣ����ѭ���ɣ�Ҫ����ctrl+Z���һس���ֹͣ��
    {
        for (i = 1; s[i] && s[i] != c; i++) //ע���Ǵ�1��ʼ�����Ǵ�0��ʼ
            ;                               //��ѭ����
        if (s[i])
            putchar(s[i - 1]);
        else //�ַ���ֻ��'\0'==0��������һ����ʾs��û��������ַ�c���������ǿո��������ַ�
            putchar(c);
    }

    return 0;

    // �ܽ�һ��Ŀǰѧ�������������ʽ��
    // ���룺scanf(),freopen(),fscanf(),getchar(),sscanf(),fgets()
    // �����printf(),freopen(),fprintf(),putchar(),sprintf()
}