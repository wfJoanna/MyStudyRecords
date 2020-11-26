#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = "12:34:56";
    int HH, MM, SS;
    sscanf(s, "%d:%d:%d", &HH, &MM, &SS); //凭感觉写的，居然写对了
    printf("%d %d %d\n", HH, MM, SS);
    return 0;
}