#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5000 + 10
int main()
{
    char buf[MAX], s[MAX];
    int n = 0, max = 0, x, y;
    int stobuf[MAX]; //����stobuf[i]�洢�ľ���s[i]��buf�е�����

    fgets(buf, sizeof(buf), stdin);

    for (int i = 0; i < strlen(buf); i++)
    {
        if (isalpha(buf[i]))
        {
            stobuf[n] = i;
            s[n++] = toupper(buf[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i - j >= 0 && i + j < n; j++) //��s[i]Ϊ���ģ�������չ���ж�s[i-j]�Ƿ����s[i+j]
        {
            if (s[i - j] != s[i + j])
                break;
            if (j * 2 + 1 > max)
            {
                max = j * 2 + 1;
                x = stobuf[i - j];
                y = stobuf[i + j];
            }
        }

        for (int j = 0; i - j >= 0 && i + 1 + j < n; j++) //��s[i]��s[i+1]Ϊ����
        {
            if (s[i - j] != s[i + 1 + j])
                break;
            if (j * 2 + 2 > max)
            {
                max = j * 2 + 2;
                x = i - j;
                y = i + 1 + j;
            }
        }
    }

    printf("max = %d\n", max);
    for (int i = x; i <= y; i++)
        printf("%c", buf[i]);
    printf("\n");

    return 0;
}