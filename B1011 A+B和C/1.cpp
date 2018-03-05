#include <stdio.h>
int main(){
	long long a,b,c;
	int T,n = 1;
	scanf("%d",&T);
	while (n != T+1){
		scanf("%lld%lld%lld",&a,&b,&c);
		if (a + b > c)
			printf("Case #%d: true\n",n);
		else 
			printf("Case #%d: false\n",n);
		n++;
	}
} 
