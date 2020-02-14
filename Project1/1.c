#include<stdio.h>
int main(void)
{
    printf("Some var in C\n");
    printf("In the file %s, line %d, I set a printf in the function %s.\n Hope you like it!\n",__FILE__,__LINE__,__func__);
    return 0;
}
