/*�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������

�����ʽ��

������2���зֱ������������Щ�����Լ�Ӧ����������֡����ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����105���ַ��Ĵ���
���õ��ַ�������ĸ[a-z, A-Z]������0-9���Լ��»��ߡ�_��������ո񣩡���,������.������-������+���������ϵ���������Ŀ��֤��2����������ִ��ǿա�

ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������

�����ʽ��
��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�

����������
7+IE.
7_This_is_a_test.
���������
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
