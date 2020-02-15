//#include"big.h"
#include<stdio.h>
#include<string.h>

char diva[BUFSIZ], divb[BUFSIZ];
char result_tmp[BUFSIZ];
char final[BUFSIZ];

char* bigdiv(char* diva, int lena, char* divb, int lenb) {        //大数除法函数。
    int i, j, k;
    char* result = NULL;
    if((lena < lenb)|| ((lena == lenb) && (strcmp(diva, divb) < 0))){  //去除了以小除大的判断
        printf("0 余数=");//求余数
        for(i=0; i<lena; i++)
            printf("%d",diva[i]-'0');
        printf("\n");
        return NULL;
    }
    k = 0;
    while (1) {                        //死循环只有当lena和lenb相等时跳出循环，因为会不断的在divb数组前加0所以该数组的长度，
                                        //会不断的变化当两者相等时说明已经无法在作减法。
        result_tmp[k] = 0;
        while (strcmp(diva, divb) >= 0) { //用字符串比较的方法是一个亮点，很巧妙。因为strcmp()比较的方式是从前到后依次比较 
            int i = 0, j;                  //如果相等则向后移动一位一旦发现不等则立即返回忽略后面的所有数据。
            while (1) {
                if (diva[i] == '0') i++;//去除diva高位前面的0
                else {
                    j = i;              //去除divb高位填充的0
                    break;
                }
            }
            for (; i < lenb; i++)            //作减法
                diva[i] = diva[i] - divb[i] + '0';
            for (i = lenb - 1; i > j; i--)       //每作一组减法就整理数组，这种整理数组在前几篇中都有使用。
                if (diva[i] < '0') {              //不过在这里不是整理结果数组而是diva数组，结果保存在ａ数组中不用整理
                    diva[i] += 10;;
                    diva[i - 1]--;
                }
            result_tmp[k]++;
        }
        k++;
        if (lena == lenb)   break;
        for (i = lenb - 1; i >= 0; i--)   //将divb中的元素先后移位，同时扩大divb长度并且在divb前端补一位0。
            divb[i + 1] = divb[i];
        divb[0] = '0';               //由于数组后移所以divb[0]每次移动后都为空，所以每次用0补齐。
        lenb++;
        divb[lenb] = '\0';           //在结尾加上字符串的结束标记。
    }
    i = 0; j = 0;
    while (result_tmp[i] == 0) i++;
    for (; i < k; i++) {
        final[j++] = result_tmp[i] + '0';
    }
    result = final;
 
    printf(" 余数=");
    j=0;//求余数
    while(diva[j]=='0')  j++;
    if(j==lena)
    {
        printf("0\n");
        return result;
    }
    for(; j< lena; j++)
        printf("%d",diva[j]-'0');
    printf("\n");

    return result;
}
int main(void) {                                                 //利用main测试方法，用puts打印结果。               
    int lena, lenb;
    char* result = NULL, sa[BUFSIZ], sb[BUFSIZ];
    printf("输入被除数a：");
    scanf_s("%s", sa, BUFSIZ);
    printf("输入除数b：");
    scanf_s("%s", sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigdiv(sa, lena, sb, lenb);

    if(result!=NULL) puts(result);
    return 0;
}
