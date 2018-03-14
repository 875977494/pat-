/*旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。
可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/
#include <stdio.h>
const int maxn = 1000000;
int main(){
	char s1[100005],s2[100005];
	char c1 = '+',c2 = '-',c3 = ',',c4 = '.';
	bool HashTable[maxn] = {false};
	gets(s1);
	gets(s2);
	for (int i = 0;s1[i] != '\0';i++){
		if (s1[i] >= 'A' && s1[i] <= 'Z'){
			HashTable[s1[i]] = true;
			HashTable[s1[i] + 32] = true;
		}
		else if (s1[i] >= 'a' && s1[i] <= 'a'){
			HashTable[s1[i]] = true;
			HashTable[s1[i] - 32] = true;
		}
		else HashTable[s1[i]] = true;
	}
	int c = 0;
	for (int j = 0;s2[j] != '\0';j++){
		if (HashTable[c1] == true) {//||HashTable[c2] == true ||HashTable[c3] == true||HashTable[c4] == true){
			if (s2[j] >= 'A' && s2[j] <= 'Z') continue;
		}
		if (HashTable[s2[j]] == false) {
			printf("%c",s2[j]);
			c++;
		}
	}
	if (c == 0) printf("\n");
}
