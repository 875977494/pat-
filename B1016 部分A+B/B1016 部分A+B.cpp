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
	while(X != 0){  //���Ҫ��ס�����whileѭ��+if�жϿ���ʵ��ȡ��һ������ÿһλ�Ĺ��ܣ� 
		if(X%10 == x)  
			p = p * 10 + x;
		X = X/10;
	}
	return p;
}
