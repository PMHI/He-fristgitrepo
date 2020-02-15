#include<stdio.h>
#include<math.h>

int main(void)
{
    double num1 = 1.0, num2 = 1.0, num3 = 2.0;
    double ans1 = 1.0,ans2 = 0.118;
    while (fabs(ans2 - ans1) > 0.00000000000001)
    {
        ans1 = ans2;
        num1 = num2;
        num2 = num3;
        num3 = num1 + num2;
        ans2 = fabs(num2 / num3);
        printf("num3:%.16f    fabs:%.16f\n",num3, ans2);
    }
    printf("done!");
    return 0;
}