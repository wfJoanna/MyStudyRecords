#include <stdio.h>

int main()
{
    int c, p = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%s", p ? "“" : "”");
            // 注意两点：
            // 1，c语言中单引号和双引号不一样，单引号表示字符，双引号表示字符串；
            // 2，中文的引号不算单个字符，只能当作字符串（似乎中文符号都是这样的）
            p = !p;
        }
        else
            putchar(c);
    }
    return 0;
}