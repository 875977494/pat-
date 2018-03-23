/*给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个(0, 10000)区间内的正整数N。

输出格式：
如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct num{
	int data[4] = {0};
};

bool cmp(int a,int b){
	return a < b;
}

num C_6174(){
	num a;
	a.data[0] = 4;
	a.data[1] = 7;
	a.data[2] = 1;
	a.data[3] = 6;
	return a;
}
num ReadN(int N){
	num n;
	for (int i = 0;i < 4;i++){
		n.data[i] = N % 10;
		N = N / 10;
	}
	sort(n.data,n.data + 4,cmp);
	return n;
}

num Reverse(num a){
	num b;
	for (int i = 0;i < 4;i++){
		b.data[i] = a.data[3 - i];
	}
	return b;
}

bool isEq(num a,num b){
	for (int i = 0;i < 4;i++){
		if (a.data[i] == b.data[i]){
			continue;
		}
		else return 0;
	}
	return 1;
}

void print(num a){
	for (int i = 3;i >= 0;i--){
		printf("%d",a.data[i]);
	}
}

num sub(num a,num b){
	num c;
	for (int i = 0;i < 4;i++){
		if (a.data[i] < b.data[i]){
			a.data[i] += 10;
			a.data[i + 1]--;
		}
		c.data[i] = a.data[i] - b.data[i];
	}
	return c;
}

int main(){
	int n;
	scanf("%d",&n);
	num p1 = ReadN(n);
	num p2 = Reverse(p1);
	num p3;
	num c = C_6174();
	while (isEq(p3,c) != 1){
		if (isEq(p1,p2) == 1){
			print(p1);
			printf(" - ");
			print(p2);
			printf(" = ");
			printf("0000");
			return 0;
		}
		p3 = sub(p1,p2);
		print(p1);
		printf(" - ");
		print(p2);
		printf(" = ");
		print(p3);
		printf("\n");
		p1 = p3;
		sort(p1.data,p1.data + 4,cmp);
		p2 = Reverse(p1);
	}
}
