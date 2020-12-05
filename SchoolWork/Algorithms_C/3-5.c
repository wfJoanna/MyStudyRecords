#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5000 + 10
int main()
{
    char buf[MAX], s[MAX];
    int n = 0, max = 0;

    fgets(buf, sizeof(buf), stdin); //从stdin读取完整的一行（因为一旦读到'\n'就停止并在末尾添上'\0'），且读取不超过sizeof(buf)-1个字符，读取到buf数组
    //注意！fgets()是会读入'\n'的！！！同时strlen()返回的长度也是包含'\n'的！

    for (int i = 0; i < strlen(buf); i++)
    {
        if (isalpha(buf[i]))          //isalpha()判断字符是否是字母
            s[n++] = toupper(buf[i]); //toupper()返回字符大写形式，tolower()返回字符小写形式
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) //判断s[i]到s[j]这段字符串是不是回文串
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
