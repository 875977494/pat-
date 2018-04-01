/*输入格式： 
输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。

输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
*/

#include <cstdio>
#include <cctype>
int max(int a[]){
	int maxi = 0;
  	for (int i = 0;i < 26;i++){
        	if (a[i] > a[maxi]) maxi = i;
          	else continue;
  }
  return maxi;
}
int main(){
	char s[1010];
	gets(s);
	int count[26] = {0}; 
	for (int i = 0;s[i] != '\0';i++){
		s[i] = tolower(s[i]);
//		printf("%c",s[i]);
		if (islower(s[i])) {
			count[s[i] - 'a']++;
		}
	}
  	int t = max(count);
  	int max_t = count[t];
	printf("%c %d",t + 'a',max_t);
} 


