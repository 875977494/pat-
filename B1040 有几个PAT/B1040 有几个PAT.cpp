/*字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
#include <cstdio>
#include <cstring>
const int mod = 1000000007;
const int maxn =  100010;
int main(){
	char s[maxn];
	gets(s);
	int len = strlen(s);
	int num_p[maxn] = {0};
	for (int i = 0;i < len;i++){
		if (i > 0) num_p[i] = num_p[i - 1];
		if (s[i] == 'P') num_p[i]++;
	}
	int num_t = 0;
	long long num = 0;
	for (int i = len - 1;i >= 0;i--){
		if (s[i] == 'T') num_t++;
		else if (s[i] == 'A') num = num + num_t * num_p[i];
	}
	printf("%lld",num % mod);
	return 0;
} 
