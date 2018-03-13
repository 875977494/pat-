/*“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只
要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。*/

#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int main(){
	int n;
	vector<int> c;
	char s[101];
	scanf("%d",&n);
	int p = 0,loc_t,t = 0,other = 0,loc_p;
	while(n--){
		scanf("%s",s);
		int len = strlen(s);
		for (int i = 0;s[i] != '\0';i++){
			//printf("%c\n",s[i]); 
			if (s[i] == 'P') {
				p++;
				loc_p = i;
			}
			else if (s[i] == 'T') {
				t++;
				loc_t = i;
			}
			else if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T'){
				other = 1;
			}
		}
		if (other == 1 || loc_t - loc_p <= 1 || p != 1 || t != 1) c.push_back(-1);
		else if (len - loc_t - 1 - loc_p * (loc_t - loc_p - 2) == loc_p) c.push_back(1);
		else c.push_back(-1);
		p = 0;t = 0;other = 0;
	}
	for (int i = 0;i < c.size();i++){
		if (c[i] == 1) printf("YES\n");
		else printf("NO\n");
	}
}
