/*�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P),��4λ(A),��6λ(T)���ڶ���PAT�ǵ�3λ(P),��4λ(A),��6λ(T)��

�ָ����ַ�������һ�������γɶ��ٸ�PAT��

�����ʽ��
����ֻ��һ�У�����һ���ַ��������Ȳ�����105��ֻ����P��A��T������ĸ��

�����ʽ��
��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����

����������
APPAPT
���������
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
