/*����������13���Ƽ����ģ�
�����˵�0�������˳�Ϊtret��
����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��
�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�

�����ʽ��
��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�

����������
4
29
5
elo nov
tam
���������
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
	int flag = 0;  //flag����0�������ģ�flag����1������ 
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
