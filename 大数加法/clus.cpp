//#include"big.h"
//将整个加法写成一个方法，然后在main函数中调用。
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char* bigadd(char* adda, int lena, char* addb, int lenb) {     //加法运算的方法。
    int num = '0', i, j;
    for (i = 0; i < lena; i++) {                                      //将字符编码的数字转换为对应的数，
        adda[i] = adda[i] - num;                                  //例如6实际在字符串中存储的是54，
    }                                                         //减去0对应的48得到真实的6存储在字符数组中。
    for (i = 0; i < lenb; i++) 
        addb[i] = addb[i] - num;
    int lensum;                                             //求出结果数组的长度。
    lensum = lena > lenb ? lena : lenb;
    lensum++;
    char* result = NULL, *final = NULL;                             //result用于返回结果集，final数组用于整理结果集。
    if ((result = (char*)calloc(lensum + 1, 1)) == NULL) {
        printf("result calloc failed!\n");
        return 0;
    }
    if ((final = (char*)calloc(lensum + 1, 1)) == NULL) {
        printf("final calloc failed!\n");
        return 0;
    }
    for (i = 0; (i < lena) && (i < lenb); i++) {                    //循环的给每一位作加法
        result[i] = adda[lena - i - 1] + addb[lenb - i - 1];
    }
    if (lena > lenb) {                                          //使用判断将较大数的高位也写入结果数组
        for (i = lenb; i < lena; i++) {
            result[i] = adda[lena - i - 1];
        }
    }
    if (lenb > lena) {
        for (i = lena; i < lenb; i++) {
            result[i] = addb[lenb - i - 1];
        }
    }
    for (j = 0; j < lensum - 1; j++) {                                //整理结果数组的每一位，满10进一。
        if (result[j] > 9) {
            result[j] = result[j] % 10;
            result[j + 1] ++;
            //tmp = result[k] / 10;
            //result[k] = result[k] % 10;
            //result[k + 1] += tmp;
        }
    }
    j = 0;
    if (result[lensum - 1] != 0) {                                 //去掉前前导0将结果处理后写到final数组中。
        final[j] = result[lensum - 1] + '0';
        j++;
    }
    for (i = lensum - 2; i >= 0; i--) {
          final[j++] = result[i] + '0';
    }
    memcpy(result, final, lensum);   
    result[j] = '\0';
    free(final);
    return result;
}
int main(void) {                                                 //利用main测试方法，用puts打印结果。               
    int lena, lenb;
    char* result, sa[BUFSIZ], sb[BUFSIZ];
    printf("输入相加第一个数a：");
    scanf_s("%s",sa, BUFSIZ);
    printf("输入相加第二个数b：");
    scanf_s("%s",sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigadd(sa, lena, sb, lenb);
    puts(result);

    free(result);
    return 0;
}

