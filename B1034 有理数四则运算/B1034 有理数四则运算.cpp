/*输入格式：
输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。

输出格式：
分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，
其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。

输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
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
//加法
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	print(add(a,b)); 
	printf("\n");
//减法
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	print(sub(a,b)); 
	printf("\n");
//乘法
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	print(mul(a,b)); 
	printf("\n");
//除法 
	print(a);
	printf(" / ");
	print(b);
	printf(" = ");
	if (b.numerator == 0) printf("Inf");
	else print(div(a,b)); 
	return 0;
}
