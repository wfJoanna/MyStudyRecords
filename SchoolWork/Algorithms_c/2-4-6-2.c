#include <stdio.h>

int main()
{
    /*��һ��
    int i,a,b,c;
    for(i=100; i<=999; i++)
    {
    	a = i%10; 
    	b = i/10%10;  
    	c = i/100;  
    	if(i == a*a*a + b*b*b + c*c*c)
    	    printf("%d\n",i);
    }

    return 0;
    */
    /*�����������������ɣ�ûɶ��Խ��*/
    int a, b, c;
    for (a = 1; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                if (a * 100 + b * 10 + c == a * a * a + b * b * b + c * c * c)
                    printf("%d\n", a * 100 + b * 10 + c);
            }
        }
    }
    return 0;
}