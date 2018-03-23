/*������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����Ȼ���õ�1�����ּ���2�����֣����õ�һ���µ����֡�
һֱ�ظ������������Ǻܿ��ͣ���С����ֺڶ���֮�Ƶ�6174��������������Ҳ��Kaprekar������

���磬���Ǵ�6767��ʼ�����õ�
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
�ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�

�����ʽ��
�������һ��(0, 10000)�����ڵ�������N��

�����ʽ��
���N��4λ����ȫ��ȣ�����һ���������N - N = 0000�������򽫼����ÿһ����һ���������ֱ��6174��Ϊ����֣������ʽ��������ע��ÿ�����ְ�4λ����ʽ�����

��������1��
6767
�������1��
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
��������2��
2222
�������2��
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
