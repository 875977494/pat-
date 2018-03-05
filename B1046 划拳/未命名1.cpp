#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	int a,A,b,B; // ¼×º° ¼×»® ÒÒº° ÒÒ»®
	int ca = 0,cb = 0;
	while(N--){
		scanf("%d%d%d%d",&a,&A,&b,&B);
		if (a+b == A&& a+b == B)
			continue;
		else if(a+b == A)
			cb++;
		else if(a+b == B) 
			ca++;
		else 
			continue;
	}
	printf("%d %d",ca,cb);
}
