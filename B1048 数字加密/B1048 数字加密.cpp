/*本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：
输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 101;
int main(){
	char s1[maxn],s2[maxn],S[maxn] = {0};
	scanf("%s %s",s1,s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	reverse(s1,s1 + len1);
	reverse(s2,s2 + len2);
	int len = max(len1,len2);
	int a,b,temp;
	for (int i = 0;i < len;i++){
		a = i < len1 ? s1[i] - '0' : 0;
		b = i < len2 ? s2[i] - '0' : 0;
		if (i % 2 == 0){
			temp = a + b;
			temp = temp % 13;
			if (temp == 10) S[i] = 'J';
			else if (temp == 11) S[i] = 'Q';
			else if (temp == 12) S[i] = 'K';
			else S[i] = temp + '0';
		}else {
			temp = b - a;
			if (temp < 0) temp += 10;
			S[i] = temp + '0';
		}
	}
	reverse(S,S + len);
	for (int i = 0;i < len;i++) printf("%c",S[i]);
} 
