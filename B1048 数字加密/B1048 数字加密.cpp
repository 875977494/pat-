/*����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺
������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��
������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��
��һ����������ܺ�Ľ����

����������
1234567 368782971
���������
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
