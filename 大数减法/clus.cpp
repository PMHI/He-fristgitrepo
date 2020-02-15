//#include"big.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char* bigsub(char* suba, int lena, char* subb, int lenb) {  //���������ĵķ�����
    int lensum, num = '0';
    int i, j, k, tmp;
    lensum = lena > lenb ? lena : lenb;
    for (i = 0; i < lena; i++) {                                   //��ASCII���������ת��Ϊ���������ִ洢�����ڼ��㡣
        suba[i] = suba[i] - num;                               //�����ӷ�ע���������ӡ�
    }
    for (i = 0; i < lenb; i++) {
        subb[i] = subb[i] - num;
    }
    char* result = NULL, * final = NULL;                             //result���ڷ��ؽ������final������������������
    if ((result = (char*)calloc(lensum + 2, 1)) == NULL) {
        printf("result calloc failed!\n");
        return 0;
    }
    if ((final = (char*)calloc(lensum + 2, 1)) == NULL) {
        printf("final calloc failed!\n");
        return 0;
    }
    for (i = 0, j = 0; i < lena && j < lenb; i++, j++) {                 //calloc()���������������λ���� ��lensum�� ����СΪ ��1�� �ֽڵ��ڴ�ռ�
        result[i] = suba[lena - i - 1] - subb[lenb - i - 1];           //����ȫ����ʼ��Ϊ0������ָ���ڴ��ָ��
    }
    if (lena > lenb) {                        //�жϣ�������λд��result��������С�
        for (i = lenb; i < lena; i++) {
            result[i] = suba[lena - i - 1];
        }
    }
    if (lenb > lena) {                        //����ֻ������С��������жϿ���ɾ����
        for (i = lena; i < lenb; i++) {
            result[i] = subb[lenb - i - 1];
        }
    }
    for (k = 0; k < lensum - 1; k++) {              //��������ͬ�����ӷ����ƣ�ֻ���жϷ������˶��ѡ�
        if (result[k] < 0) {
            result[k] = result[k] + 10;
            result[k + 1] -= 1;
        }
    }
    j = 0;
    if (result[lensum - 1] != 0) {             //�������ȥ��ǰ��0������final�����С�
        final[j] = result[lensum - 1] + num;
        j++;
    }
    for (i = lensum - 2; i >= 0; i--) {
        final[j++] = result[i] + num;
    }
    memcpy(result, final, lensum);                                         //�ٰ�resultָ��ָ��final�����У�������resultָ�롣   
    result[lensum + 1] = '\0';
    free(final);                        //��ָ��ָ��final���鲢���������ָ�롣
    return result;
}
int main(void) {                                                 //����main���Է�������puts��ӡ�����               
    int lena, lenb;
    char* result, sa[BUFSIZ], sb[BUFSIZ];
    printf("���뱻����a��");
    scanf_s("%s", sa, BUFSIZ);
    printf("�������b��");
    scanf_s("%s", sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigsub(sa, lena, sb, lenb);
    puts(result);

    free(result);
    return 0;
}
