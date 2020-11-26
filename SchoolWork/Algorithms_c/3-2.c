#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int lights[1001] = {0};
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j % i == 0)
                lights[j] = !lights[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (lights[i] == 1)
            printf("%d ", i);
    }
    return 0;
}