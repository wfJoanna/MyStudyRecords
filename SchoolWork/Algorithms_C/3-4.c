#include <stdio.h>
#include <string.h>
int main()
{
    char s[20], buf[99];
    int abc, de, x, y, z, ok, count = 0;

    scanf("%s", s); //ע������sǰ��û��&��scanf("%s")ֻ�ܶ�ȡһ���������ַ�����һ�����ո�TAB���س����ͻ�ͣ����

    for (abc = 100; abc <= 999; abc++)
    {
        for (de = 10; de <= 99; de++)
        {
            x = abc * (de % 10);
            y = abc * (de / 10);
            z = abc * de;

            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z); //sprintf()����������ַ���
            ok = 1;
            for (int i = 0; i < strlen(buf); i++) //strlen()�����ַ����Ľ������'\0'֮ǰ���ַ�������Ҳ�����ַ���ʵ�ʳ��ȣ�buf[strlen(buf)]=='\0'
            {
                if (strchr(s, buf[i]) == NULL) //strchr(str,c)�������ַ���str�е�һ�γ����ַ�c��λ�ã����δ�ҵ����ַ��򷵻� NULL
                    ok = 0;
            }

            if (ok)
            {
                printf("<%d>\n", ++count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
            }
        }
    }
    printf("The number of solutions = %d\n", count);
    return 0;
}