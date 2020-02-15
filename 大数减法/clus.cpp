//#include"big.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char* bigsub(char* suba, int lena, char* subb, int lenb) {  //大数减法的的方法。
    int lensum, num = '0';
    int i, j, k, tmp;
    lensum = lena > lenb ? lena : lenb;
    for (i = 0; i < lena; i++) {                                   //将ASCII编码的数字转换为真正的数字存储，便于计算。
        suba[i] = suba[i] - num;                               //大数加法注释中有例子。
    }
    for (i = 0; i < lenb; i++) {
        subb[i] = subb[i] - num;
    }
    char* result = NULL, * final = NULL;                             //result用于返回结果集，final数组用于整理结果集。
    if ((result = (char*)calloc(lensum + 2, 1)) == NULL) {
        printf("result calloc failed!\n");
        return 0;
    }
    if ((final = (char*)calloc(lensum + 2, 1)) == NULL) {
        printf("final calloc failed!\n");
        return 0;
    }
    for (i = 0, j = 0; i < lena && j < lenb; i++, j++) {                 //calloc()有两个参数，本次会分配 ‘lensum’ 个大小为 ‘1’ 字节的内存空间
        result[i] = suba[lena - i - 1] - subb[lenb - i - 1];           //并且全部初始化为0，返回指向内存的指针
    }
    if (lena > lenb) {                        //判断，并将高位写入result结果数组中。
        for (i = lenb; i < lena; i++) {
            result[i] = suba[lena - i - 1];
        }
    }
    if (lenb > lena) {                        //由于只允许大减小所以这个判断可以删除。
        for (i = lena; i < lenb; i++) {
            result[i] = subb[lenb - i - 1];
        }
    }
    for (k = 0; k < lensum - 1; k++) {              //整理结果，同大数加法类似，只是判断方法变了而已。
        if (result[k] < 0) {
            result[k] = result[k] + 10;
            result[k + 1] -= 1;
        }
    }
    j = 0;
    if (result[lensum - 1] != 0) {             //将结果集去除前导0后整理到final数组中。
        final[j] = result[lensum - 1] + num;
        j++;
    }
    for (i = lensum - 2; i >= 0; i--) {
        final[j++] = result[i] + num;
    }
    memcpy(result, final, lensum);                                         //再把result指针指向final数组中，并返回result指针。   
    result[lensum + 1] = '\0';
    free(final);                        //将指针指向final数组并返回数组的指针。
    return result;
}
int main(void) {                                                 //利用main测试方法，用puts打印结果。               
    int lena, lenb;
    char* result, sa[BUFSIZ], sb[BUFSIZ];
    printf("输入被减数a：");
    scanf_s("%s", sa, BUFSIZ);
    printf("输入减数b：");
    scanf_s("%s", sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigsub(sa, lena, sb, lenb);
    puts(result);

    free(result);
    return 0;
}
