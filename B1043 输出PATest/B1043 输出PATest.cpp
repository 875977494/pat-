/*����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ���
��Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��ֱ�������ַ����������

�����ʽ��
������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��
��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
redlesPayBestPATTopTeePHPereatitAPPT
���������
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

