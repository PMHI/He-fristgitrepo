#include<stdio.h>
int main(void)
{
    printf("In the file %s, line %d, I set a printf in the function %s. Hope you like it!\n",__FILE__,__LINE__,__func__);
    return 0;
}
