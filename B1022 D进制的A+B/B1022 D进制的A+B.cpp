/*
������һ�������θ���3������A��B��D��

�����ʽ��

���A+B��D��������

����������
123 456 8
���������
1103
*/
#include <stdio.h>
int main(){
	int d,i = 0;
	int a,b,sum;
	int D[100];
	scanf("%d%d%d",&a,&b,&d);
	sum = a + b;
	while (1){
		D[i] = sum % d;
		sum = sum / d;
		if (sum == 0) break;
		else i++;
	}
	for (i;i >= 0;i--) printf("%d",D[i]);
} 
