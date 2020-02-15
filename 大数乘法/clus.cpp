//#include"big.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* bigmul(char* m, int lena, char* f, int lenb) {  //乘法运算函数。
    int i, j, k, lensum, tmp_result, carry, num = '0';
    lensum = lena + lenb;                               //确定结果数组的长度。
    for (i = 0; i < lena; i++) {                            //将ASCII码转为对应的数字存储。
         m[i] = m[i] - num;
    }
    for (i = 0; i < lenb; i++) {
        f[i] = f[i] - num;
    }
    char* result = NULL, * final = NULL;                             //result用于返回结果集，final数组用于整理结果集。
    if ((result = (char*)calloc(lensum + 1, 1)) == NULL) {
        printf("result calloc failed!\n");
        return 0;
    }
    if ((final = (char*)calloc(lensum + 1, 1)) == NULL) {
        printf("final calloc failed!\n");
        return 0;
    }
    for (i = 0; i < lenb; i++) {                      //为被乘数作一趟乘法。
        for (j = 0; j < lena; j++) {
               tmp_result = f[lenb - i - 1] * m[lena - j - 1];
               result[j + i] += tmp_result;
        }
        for (k = 0; k <= j + i - 1; k++) {                 //每作一趟乘法整理一次结果数组。
            if (result[k] > 9) {
                carry = result[k] / 10;
                result[k] = result[k] % 10;
                result[k + 1] += carry;
            } 
        }
    }
    j = 0;
    if (result[lensum - 1] != 0) {                  //去除前导零将结果整理到final数组中。
        final[j] = result[lensum - 1] + num;
        j++;
        
    }
    for (i = lensum - 2; i >= 0; i--) {
        final[j++] = result[i] + num;
        
    }
    memcpy(result, final, lensum);
    result[j] = '\0';
    free(final);
    return result;
}
int main(void) {                                                 //利用main测试方法，用puts打印结果。               
    int lena, lenb;
    char* result, sa[BUFSIZ], sb[BUFSIZ];
    printf("输入相乘第一个数a：");
    scanf_s("%s", sa, BUFSIZ);
    printf("输入相乘第二个数b：");
    scanf_s("%s", sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigmul(sa, lena, sb, lenb);
    puts(result);

    free(result);
    return 0;
}
