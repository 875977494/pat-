/*�����ʽ�� 
������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��
��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��

����������
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
���������
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


