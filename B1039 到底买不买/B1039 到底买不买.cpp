/*�����ʽ��
 ÿ���������1������������ÿ�����������ֱ���2�����Ⱥ����̯�����鴮��С���������鴮��������������1000�����ӡ�
 �����ʽ��
 �������������һ���������Yes���Լ��ж��ٶ�������ӣ����������������һ���������No���Լ�ȱ�˶������ӡ������1���ո�ָ���
 ��������1��
 ppRYYGrrYBR2258
 YrR8RrY
 �������1��
 Yes 8
 ��������2��
 ppRYYGrrYB225
 YrR8RrY
 �������2��
 No 2*/

#include <cstdio>
#include <cstring>
const int maxn = 10000;
int main(){
    char c1[1001],c2[1001];
    int a[maxn] = {0};
    gets(c1);
    gets(c2);
    int len = strlen(c2);
    for (int i = 0;c1[i] != '\0';i++){
        a[c1[i]]++;
    }
    /*for (int i = 0;i < maxn;i++){
        printf("%d ",a[i]);
    }*/
    int un = 0, c = 0;
    for (int i = 0;c2[i] != '\0';i++){
        if (a[c2[i]] > 0){
            c++;
            a[c2[i]]--;
        }
        else if (a[c2[i]] <= 0) un++;
    }
    int sum = 0;
    for (int i = 0; i < maxn;i++){
        sum += a[i];
    }
    if (c == len) {
        printf("Yes %d",sum);
    }
    else if (c < len){
        printf("No %d",un);
    }
}
