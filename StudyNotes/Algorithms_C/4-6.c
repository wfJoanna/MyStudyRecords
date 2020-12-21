#include <stdio.h>

int factorial(int n)
{
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main()
{
    printf("%d\n", factorial(3));
    return 0;
}