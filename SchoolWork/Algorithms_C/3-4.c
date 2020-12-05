#include <stdio.h>
#include <string.h>
int main()
{
    char s[20], buf[99];
    int abc, de, x, y, z, ok, count = 0;

    scanf("%s", s); //注意啦，s前面没有&。scanf("%s")只能读取一个连续的字符串，一遇到空格、TAB、回车符就会停下来

    for (abc = 100; abc <= 999; abc++)
    {
        for (de = 10; de <= 99; de++)
        {
            x = abc * (de % 10);
            y = abc * (de / 10);
            z = abc * de;

            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z); //sprintf()就是输出到字符串
            ok = 1;
            for (int i = 0; i < strlen(buf); i++) //strlen()返回字符串的结束标记'\0'之前的字符个数，也就是字符串实际长度，buf[strlen(buf)]=='\0'
            {
                if (strchr(s, buf[i]) == NULL) //strchr(str,c)返回在字符串str中第一次出现字符c的位置，如果未找到该字符则返回 NULL
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