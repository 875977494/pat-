#include <stdio.h>
int main(){
	int c1,c2;
	int ans;
	int h,m,s;
	scanf("%d%d",&c1,&c2);
	ans = c2-c1;
	if(ans % 100 >= 50)    //������������һ�����У��������Ч�� 
		ans = ans/100 + 1;
	else
		ans = ans/100;
	printf("02%d:%02d:%02d",ans/3600,ans%3600/60,ans%60); // ��Ⱥ���Ҫ 02 ���������λ 
} 
