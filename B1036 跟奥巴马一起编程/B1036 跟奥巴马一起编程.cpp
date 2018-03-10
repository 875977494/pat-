#include <stdio.h>
int main(){
	int N;
	char a;
	int i,j;
	int l;
	scanf("%d %c",&N,&a);
	if (N % 2 == 0) l = N / 2;
	else l = N / 2 + 1;
	for (i = 0;i < l;i++){
		for (j = 0;j < N;j++){
			if (i == 0|| i == l - 1) printf("%c",a);
			else if (j == 0||j == N - 1) printf("%c",a);
			else printf(" ");
		}
		printf("\n");
	}
} 
