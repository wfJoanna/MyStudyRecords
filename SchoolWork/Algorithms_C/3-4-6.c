#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = "12:34:56";
    int HH, MM, SS;
    sscanf(s, "%d:%d:%d", &HH, &MM, &SS); //ƾ�о�д�ģ���Ȼд����
    printf("%d %d %d\n", HH, MM, SS);
    return 0;
}