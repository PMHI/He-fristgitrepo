//#include"big.h"
#include<stdio.h>
#include<string.h>

char diva[BUFSIZ], divb[BUFSIZ];
char result_tmp[BUFSIZ];
char final[BUFSIZ];

char* bigdiv(char* diva, int lena, char* divb, int lenb) {        //��������������
    int i, j, k;
    char* result = NULL;
    if((lena < lenb)|| ((lena == lenb) && (strcmp(diva, divb) < 0))){  //ȥ������С������ж�
        printf("0 ����=");//������
        for(i=0; i<lena; i++)
            printf("%d",diva[i]-'0');
        printf("\n");
        return NULL;
    }
    k = 0;
    while (1) {                        //��ѭ��ֻ�е�lena��lenb���ʱ����ѭ������Ϊ�᲻�ϵ���divb����ǰ��0���Ը�����ĳ��ȣ�
                                        //�᲻�ϵı仯���������ʱ˵���Ѿ��޷�����������
        result_tmp[k] = 0;
        while (strcmp(diva, divb) >= 0) { //���ַ����Ƚϵķ�����һ�����㣬�������Ϊstrcmp()�Ƚϵķ�ʽ�Ǵ�ǰ�������αȽ� 
            int i = 0, j;                  //������������ƶ�һλһ�����ֲ������������غ��Ժ�����������ݡ�
            while (1) {
                if (diva[i] == '0') i++;//ȥ��diva��λǰ���0
                else {
                    j = i;              //ȥ��divb��λ����0
                    break;
                }
            }
            for (; i < lenb; i++)            //������
                diva[i] = diva[i] - divb[i] + '0';
            for (i = lenb - 1; i > j; i--)       //ÿ��һ��������������飬��������������ǰ��ƪ�ж���ʹ�á�
                if (diva[i] < '0') {              //���������ﲻ���������������diva���飬��������ڣ������в�������
                    diva[i] += 10;;
                    diva[i - 1]--;
                }
            result_tmp[k]++;
        }
        k++;
        if (lena == lenb)   break;
        for (i = lenb - 1; i >= 0; i--)   //��divb�е�Ԫ���Ⱥ���λ��ͬʱ����divb���Ȳ�����divbǰ�˲�һλ0��
            divb[i + 1] = divb[i];
        divb[0] = '0';               //���������������divb[0]ÿ���ƶ���Ϊ�գ�����ÿ����0���롣
        lenb++;
        divb[lenb] = '\0';           //�ڽ�β�����ַ����Ľ�����ǡ�
    }
    i = 0; j = 0;
    while (result_tmp[i] == 0) i++;
    for (; i < k; i++) {
        final[j++] = result_tmp[i] + '0';
    }
    result = final;
 
    printf(" ����=");
    j=0;//������
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
int main(void) {                                                 //����main���Է�������puts��ӡ�����               
    int lena, lenb;
    char* result = NULL, sa[BUFSIZ], sb[BUFSIZ];
    printf("���뱻����a��");
    scanf_s("%s", sa, BUFSIZ);
    printf("�������b��");
    scanf_s("%s", sb, BUFSIZ);
    lena = strlen(sa);
    lenb = strlen(sb);
    result = bigdiv(sa, lena, sb, lenb);

    if(result!=NULL) puts(result);
    return 0;
}
