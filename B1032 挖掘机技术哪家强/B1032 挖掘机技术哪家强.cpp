/*
������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��

�����ڵ�1�и���������105��������N�����������������N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ���1��ʼ������ţ�����������ɼ����ٷ��ƣ���
�м��Կո�ָ���

�����ʽ��

��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�

����������
6
3 65
2 80
1 100
2 70
3 40
3 0
���������
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
