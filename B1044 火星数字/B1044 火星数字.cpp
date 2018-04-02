/*火星人是以13进制计数的：
地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/
#include <cstdio>
#include <cstring>
#include <cmath>
const char c1[12][4] = {"jan", "feb", "mar", "apr", "may", "jun" , "jly", "aug", "sep", "oct", "nov", "dec"};
const char c2[12][4] = {"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
struct Num{
	int flag = 0;
	char s[8];
	int num;
}a[100];
int main(){
	int N;
	scanf("%d",&N);
	int flag = 0;  //flag等于0，火星文，flag等于1，数字 
	getchar();
	for (int i = 0;i < N;i++){
		char s[8] = {"0"};
		gets(s);
		int num = 0;
		if (s[0] >= '0' && s[0] <= '9') flag = 1;
		if (flag == 0){
			for (int i = 0;i < 12;i++){
				if (c2[i][0] == s[0] && c2[i][1] == s[1] && c2[i][2] == s[2]){
					num += 13 * (i + 1);
				}
				if (c1[i][0] == s[0] && c1[i][1] == s[1] && c1[i][2] == s[2]){
					num += (i + 1);
				}
				if (c1[i][0] == s[4] && c1[i][1] == s[5] && c1[i][2] == s[6]){
					num += (i + 1);
				}
			}
			printf("%d\n",num);
		}
		else {
			int len = strlen(s);
			int n = 0;
			for (int i = len - 1;i >= 0;i--){
				n += (s[i] - '0') * pow(10,(len - i - 1));
			}
			int mod = n % 13;
			n = n / 13;
			if (mod == 0 && n == 0) printf("tret\n");
			else{
				if (n == 0){
					printf("%s\n",c1[mod - 1]);
				}else if (mod == 0){
					printf("%s\n",c2[n - 1]);
				}else printf("%s %s\n",c2[n - 1],c1[mod - 1]);
			}
		}
		flag = 0;
	}
} 
