#include <stdio.h>
int main()
{
    char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; //注意啦，是'\\'而不是'\'
    //之前我们是直接s[MAX]="xxxxx"，当然也可以像这里这样直接用指针，数组其实就是指针的一种

    int i, c;                      //字符可以直接声明为int，反正最后输出是putchar()，会自动转换为字符再输出
    while ((c = getchar()) != EOF) //EOF表示end of file，一般用getchar()循环读取时，都用这种形式来停止循环（但其实根本停止不了循环吧！要按了ctrl+Z并且回车才停止）
    {
        for (i = 1; s[i] && s[i] != c; i++) //注意是从1开始，不是从0开始
            ;                               //空循环体
        if (s[i])
            putchar(s[i - 1]);
        else //字符中只有'\0'==0。到了这一步表示s中没有输入的字符c，即可能是空格这样的字符
            putchar(c);
    }

    return 0;

    // 总结一下目前学到的输入输出方式：
    // 输入：scanf(),freopen(),fscanf(),getchar(),sscanf(),fgets()
    // 输出：printf(),freopen(),fprintf(),putchar(),sprintf()
}