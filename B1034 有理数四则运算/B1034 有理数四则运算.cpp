/*�����ʽ��
������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��

�����ʽ��
�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�ע�������ÿ�������������Ǹ��������������ʽ��k a/b����
����k���������֣�a/b�����������֣���Ϊ��������������ţ���������ĸΪ0���������Inf������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������

��������1��
2/3 -4/2
�������1��
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
��������2��
5/3 0/6
�������2��
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct frac{
	ll numerator;
	ll denominator;
}a,b;

ll gcd(ll a,ll b){
	if (b == 0) return a;
	else return gcd(b,a % b);
}

frac red(frac a){
	if (a.denominator < 0){
		a.denominator = -1 * a.denominator;
		a.numerator = -1 * a.numerator;
	}
	if (a.numerator == 0){
		a.denominator = 1;
	}else {
		ll c = gcd(abs(a.numerator),abs(a.denominator));
		a.numerator = a.numerator / c;
		a.denominator = a.denominator / c;
	}
	return a;
}

frac add(frac a,frac b){
	frac c;
	c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	c.denominator = a.denominator * b.denominator;
	return c;
}

frac sub(frac a,frac b){
	frac c;
	c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	c.denominator = a.denominator * b.denominator;
	return c;
}

frac mul(frac a,frac b){
	frac c;
	c.numerator = a.numerator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	return c;
}

frac div(frac a,frac b){
	frac c;
	c.numerator = a.numerator * b.denominator;
	c.denominator = a.denominator * b.numerator;
	return c;
}

void print(frac a){
	a = red(a);
	if (a.numerator < 0){
		printf("(");
	}
	if(a.denominator == 1) printf("%lld",a.numerator);
	else if (abs(a.numerator) > a.denominator){
		printf("%lld %lld/%lld",a.numerator / a.denominator,abs(a.numerator) % a.denominator,a.denominator);
	}else {
		printf("%lld/%lld",a.numerator,a.denominator);
	}
	if (a.numerator < 0) printf(")");
}

int main(){
	scanf("%lld/%lld %lld/%lld",&a.numerator,&a.denominator,&b.numerator,&b.denominator);
//�ӷ�
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	print(add(a,b)); 
	printf("\n");
//����
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	print(sub(a,b)); 
	printf("\n");
//�˷�
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	print(mul(a,b)); 
	printf("\n");
//���� 
	print(a);
	printf(" / ");
	print(b);
	printf(" = ");
	if (b.numerator == 0) printf("Inf");
	else print(div(a,b)); 
	return 0;
}
