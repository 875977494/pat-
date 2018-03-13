/*读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu*/
#include <stdio.h>
int main(){
	char n[10000];
	int i;
	int sum = 0;
	char a[11][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int x,y,z;
	scanf("%s",n);
	for (i = 0;n[i] != '\0';i++){
		sum += (n[i] - '0');
	}
	x = sum / 100;
	y = (sum - x * 100) / 10;
	z = sum - x*100 - y*10;
	if (x != 0){
		printf("%s %s %s",a[x],a[y],a[z]);
	}
	else if (x == 0 && y == 0) printf("%s",a[z]);
	else if (x == 0 && y != 0) printf("%s %s",a[y],a[z]);
}
