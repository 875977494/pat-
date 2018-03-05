#include <stdio.h>

int p(int X,int x);
int main(){
	long long A,B,a,b;
	int pa,pb;
	scanf("%lld%lld%lld%lld",&A,&a,&B,&b);
	pa = p(A,a);
	pb = p(B,b);
	printf("%d",pa+pb);
} 

int p(int X,int x){
	int p;
	while(X != 0){  //这个要记住，这个while循环+if判断可以实现取出一个数字每一位的功能； 
		if(X%10 == x)  
			p = p * 10 + x;
		X = X/10;
	}
	return p;
}
