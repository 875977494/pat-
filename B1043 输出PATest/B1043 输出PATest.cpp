/*给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。
当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/
#include <cstdio>
int min(int a[]){
	int min = a[0];
	for (int i = 1;i < 6;i++){
		if (a[i] < min) min = a[i];
	}
	return min;
}

int sum(int a[]){
	int sum = 0;
	for (int i = 0;i < 6;i++){
		sum += a[i];
	}
	return sum;
}

int main(){
	char s[10010];
	gets(s);
	int count[6] = {0};
	for (int i = 0;s[i] != '\0';i++){
		if (s[i] == 'P') count[0]++;
		if (s[i] == 'A') count[1]++;
		if (s[i] == 'T') count[2]++;
		if (s[i] == 'e') count[3]++;
		if (s[i] == 's') count[4]++;
		if (s[i] == 't') count[5]++; 
	}
	int m = min(count);
	for (int i = 0;i < 6;i++){
		count[i] = count[i] - m;
	}
	while(m--){
		printf("PATest"); 
	}
	while(1){
		if (count[0] != 0){
			printf("P");
			count[0]--;
		}
		if (count[1] != 0) {
			printf("A");
			count[1]--;
		}
		if (count[2] != 0) {
			printf("T");
			count[2]--;
		}
		if (count[3] != 0) {
			printf("e");
			count[3]--;
		}
		if (count[4] != 0) {
			printf("s");
			count[4]--;
		}
		if(count[5] != 0){
			printf("t");
			count[5]--;
		}
		if (sum(count) == 0) break;
	}
	return 0;
}

