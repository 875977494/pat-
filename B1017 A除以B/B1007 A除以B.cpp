/*����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������

�����ʽ��

������1�������θ���A��B���м���1�ո�ָ���

�����ʽ��

��1�����������Q��R���м���1�ո�ָ���

����������
123456789050987654321 7
���������
17636684150141093474 3
*/
#include <cstdio>
#include <cstring>
struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};
bign change(char str[]){
	bign a;
	a.len = strlen(str);
	for (int i = a.len - 1;i >= 0;i--){
		a.d[a.len - 1 - i] = str[i] - '0';
	}
	return a;
}
bign divide(bign a,int b,int& r){
	bign c;
	c.len = a.len;
	for (int i = a.len - 1;i >= 0;i--){
		r = r * 10 + a.d[i];
		if (r < b) c.d[i] = 0;
		else {
			c.d[i] = r / b;
			r = r % b;
 		}
 	}
 	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0){
 		c.len--;
	}
	return c; 
}
void print(bign a){
	for (int i = a.len - 1;i >= 0;i--){
		printf("%d",a.d[i]);
	}
}
int main(){
	char c[1001];
	int b;
	int r = 0;
	scanf("%s%d",c,&b);
	bign a = change(c);
	bign d = divide(a,b,r);
	print(d);
	printf(" %d",r);
	return 0;
}
