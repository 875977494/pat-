/*����������Ĺ���Ϊ��ÿ�������������ɶ�Ա��ɣ����ж�Ա���������������ӵĳɼ�Ϊ���ж�Ա�ĳɼ��ͣ��ɼ���ߵĶӻ�ʤ��

�ָ������ж�Ա�ı����ɼ��������д�����ҳ��ھ��ӡ�

�����ʽ��
�����һ�и���һ��������N��<=10000���������в�����Ա���������N�У�ÿ�и���һλ��Ա�ĳɼ�����ʽΪ����������-��Ա��� �ɼ�������
�С������š�Ϊ1��1000��������������Ա��š�Ϊ1��10�������������ɼ���Ϊ0��100��������

�����ʽ��
��һ��������ھ��ӵı�ź��ܳɼ��������һ���ո�ָ���ע�⣺��Ŀ��֤�ھ�����Ψһ�ġ�

����������
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
���������
11 176*/
#include <cstdio>
#include <stack>
#include <cmath>
const int maxn = 1001;
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int n;
	int score[maxn] = {0};
	for (int i = 0;i < N;i++){
		char temp_id[5];
		stack<char> t;
		getchar();
		scanf("%s %d",temp_id,&n);
		for (int j = 0;temp_id[j] != '-';j++){
			t.push(temp_id[j]);
		}
		int c = 0;
		for(int k = 0;t.empty() != 1;k++){
			c += (t.top() - '0') * pow(10,k);
			t.pop();
		}  // ���˻��id������ 
		score[c] += n;
	}
	int max = 0;
	for (int i = 1;i < maxn;i++){
		if (score[i] > score[max]) max = i;
	}
	printf("%d %d",max,score[max]);
}
