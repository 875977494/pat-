/*输入格式：

输入第一行给出一个正整数N（<= 100），随后N行，每行按照“编号-答案”的格式给出一道题的4个选项，“T”表示正确选项，“F”表示错误选项。选项间用空格分隔。

输出格式：

在一行中输出wifi密码。

输入样例：
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
输出样例：
13224143
*/
#include <cstdio> 
const int maxn = 101;
struct que{
	char A[4],B[4],C[4],D[4];
}q[maxn];

void true_num(char a[],char b[],char c[],char d[]){
	if (a[2] == 'T'){
		printf("%d",a[0] - 'A' + 1);
	}
	else if (b[2] == 'T') printf("%d",b[0] - 'A' + 1);
	else if (c[2] == 'T') printf("%d",c[0] - 'A' + 1);
	else if (d[2] == 'T') printf("%d",d[0] - 'A' + 1);
}

int main(){
	int N;
	scanf("%d",&N);
	for (int i = 0;i < N;i++){
		scanf("%s%s%s%s",q[i].A,q[i].B,q[i].C,q[i].D);
	}
	for (int i = 0;i < N;i++){
		true_num(q[i].A,q[i].B,q[i].C,q[i].D);
	}
}
