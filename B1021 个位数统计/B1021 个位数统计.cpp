/*给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。
例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出格式：

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

输入样例：
100311
输出样例：
0:2
1:3
3:1
*/

#include <cstdio>
#include <cstring>
using namespace std;
struct Num{
	int data[1001];
	Num(){
		memset(data,0,sizeof(data));
	}
}d;

int main(){
	int count[10] = {0};
	char N[1001];
	gets(N);
	int i = 0;
	if (N - '0' == 0) {
		printf("0:1");
		return 0;
	}
	for (i = 0;N[i] != '\0';i++){
		d.data[i] = N[i] - '0';
	}
	for (int j = i - 1;j >= 0;j--){
		if (d.data[j] == 0) count[0]++;
		else if (d.data[j] == 1) count[1]++;
		else if (d.data[j] == 2) count[2]++;
		else if (d.data[j] == 3) count[3]++;
		else if (d.data[j] == 4) count[4]++;
		else if (d.data[j] == 5) count[5]++;
		else if (d.data[j] == 6) count[6]++;
		else if (d.data[j] == 7) count[7]++;
		else if (d.data[j] == 8) count[8]++;
		else if (d.data[j] == 9) count[9]++;
	}
	for (i = 0;i < 10;i++){
		if (count[i] == 0) continue;
		else{
			printf("%d:%d\n",i,count[i]);
		}
	}
}
