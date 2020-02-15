//#include"big.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* bigmul(char* m, int lena, char* f, int lenb) {  //�˷����㺯����
    int i, j, k, lensum, tmp_result, carry, num = '0';
    lensum = lena + lenb;                               //ȷ���������ĳ��ȡ�
    for (i = 0; i < lena; i++) {                            //��ASCII��תΪ��Ӧ�����ִ洢��
         m[i] = m[i] - num;
    }
    for (i = 0; i < lenb; i++) {
        f[i] = f[i] - num;
    }
    char* result = NULL, * final = NULL;                             //result���ڷ��ؽ������final������������������
    if ((result = (char*)calloc(lensum + 1, 1)) == NULL) {
        printf("result calloc failed!\n");
        return 0;
    }
    if ((final = (char*)calloc(lensum + 1, 1)) == NULL) {
        printf("final calloc failed!\n");
        return 0;
    }
    for (i = 0; i < lenb; i++) {                      //Ϊ��������һ�˳˷���
        for (j = 0; j < lena; j++) {
               tmp_result = f[lenb - i - 1] * m[lena - j - 1];
               result[j + i] += tmp_result;
        }
        for (k = 0; k <= j + i - 1; k++) {                 //ÿ��һ�˳˷�����һ�ν�����顣
            if (result[k] > 9) {
                carry = result[k] / 10;
                result[k] = result[k] % 10;
                result[k + 1] += carry;
            } 
        }
    }
    j = 0;
    if (result[lensum - 1] != 0) {                  //ȥ��ǰ���㽫�������final�����С�
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
int main(void) {                                                 //����main���Է�������puts��ӡ�����               
    int lena, lenb;
    char* result, sa[BUFSIZ], sb[BUFSIZ];
    printf("������˵�һ����a��");
    scanf_s("%s", sa, BUFSIZ);
    printf("������˵ڶ�����b��");
    scanf_s("%s", sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigmul(sa, lena, sb, lenb);
    puts(result);

    free(result);
    return 0;
}
