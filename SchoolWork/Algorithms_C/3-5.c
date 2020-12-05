#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5000 + 10
int main()
{
    char buf[MAX], s[MAX];
    int n = 0, max = 0;

    fgets(buf, sizeof(buf), stdin); //��stdin��ȡ������һ�У���Ϊһ������'\n'��ֹͣ����ĩβ����'\0'�����Ҷ�ȡ������sizeof(buf)-1���ַ�����ȡ��buf����
    //ע�⣡fgets()�ǻ����'\n'�ģ�����ͬʱstrlen()���صĳ���Ҳ�ǰ���'\n'�ģ�

    for (int i = 0; i < strlen(buf); i++)
    {
        if (isalpha(buf[i]))          //isalpha()�ж��ַ��Ƿ�����ĸ
            s[n++] = toupper(buf[i]); //toupper()�����ַ���д��ʽ��tolower()�����ַ�Сд��ʽ
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) //�ж�s[i]��s[j]����ַ����ǲ��ǻ��Ĵ�
        {
            int ok = 1;
            for (int k = i; k <= j; k++)
            {
                if (s[k] != s[i + j - k])
                    ok = 0;
            }
            if (ok && (j - i + 1) > max)
                max = j - i + 1;
        }
    }

    printf("max = %d\n", max);

    return 0;
}
