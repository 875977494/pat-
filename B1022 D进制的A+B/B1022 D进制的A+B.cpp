/*
输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
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
