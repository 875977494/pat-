/*
了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第1行给出不超过105的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），
中间以空格分隔。

输出格式：

在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

输入样例：
6
3 65
2 80
1 100
2 70
3 40
3 0
输出样例：
2 150
*/
#include <stdio.h>
void summ(int a[],int b[],int N,int sum[]);
int findmax(int sum[],int N);
int main(){
	int N;
	scanf("%d",&N);
	int school[100005] = {0},score[100005] = {0},sum[100005] = {0};
	int i,m;
	for (i = 1;i < N + 1;i++){
		scanf("%d%d",&school[i],&score[i]);
	}
	summ(school,score,N,sum);
	m = findmax(sum,N);
	printf("%d %d",m,sum[m]);
	return 0;
}

void summ(int a[],int b[],int N,int sum[]){
	int i;
	for (i = 1;i < N + 1;i++){
		sum[a[i]] += b[i];
	}
}

int findmax(int sum[],int N){
	int i;
	int maxi = 1;
	for (i = 1;i < N+1;i++){
		if (sum[i] > sum[maxi]) maxi = i;
		else continue;
	}
	return maxi;
}
