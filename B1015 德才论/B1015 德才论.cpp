/*�δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ������ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮���ˣ���ʤ��ν֮���ӣ���ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ�
���Ӷ���֮�������С�ˣ����������ˡ���
�ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������

�����ʽ��

�����1�и���3�����������ֱ�Ϊ��N��<=105����������������L��>=60����Ϊ¼ȡ��ͷ����ߣ����·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��H��<100����
Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ
���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮��
�����ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��

���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ�������²ŷ�Ϊ����[0, 100]�ڵ����������ּ��Կո�ָ���

�����ʽ��
�����1�����ȸ����ﵽ��ͷ����ߵĿ�������M�����M�У�ÿ�а��������ʽ���һλ��������Ϣ��������������˵���Ĺ���Ӹߵ�������
ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У����·�Ҳ���У���׼��֤�ŵ����������
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student{
	char id[10];
	int de_score;
	int cai_score;
	int style;
	int score;
}S[100001],temp;

bool cmp(Student a,Student b){
	if (a.style != b.style) return a.style < b.style;
	else if (a.score != b.score) return a.score > b.score;
	else if (a.de_score != b.de_score) return a.de_score > b.de_score;
	else return strcmp(a.id,b.id) < 0;
}

int main(){
	int N;
	scanf("%d",&N);
	if (N == 0){
		printf("0");
		return 0;
	}
	int L,H,num = 0;
	scanf("%d%d",&L,&H);
	int c_s1 = 0,c_s2 = 0,c_s3 = 0,c_s4 = 0;
	while(N--){
		scanf("%s%d%d",temp.id,&temp.de_score,&temp.cai_score);
		temp.score = temp.cai_score + temp.de_score;
		if (temp.de_score >= L && temp.cai_score >= L){
			S[num] = temp;
			num++;
		}
		else continue;
		if (temp.de_score >= H && temp.cai_score >= H){
			S[num - 1].style = 1;
			c_s1++;
		}
		else if (temp.cai_score < H && temp.de_score >= H){
			S[num - 1].style = 2;
			c_s2++;
		}
		else if (temp.de_score < H && temp.cai_score < H && temp.de_score >= temp.cai_score){
			S[num - 1].style = 3;
			c_s3++;
		}
		else {
			S[num - 1].style = 4;
			c_s4++;
		}
	}
	sort(S,S + num,cmp);
	sort(S,S + c_s1,cmp); 
	sort(S + c_s1,S + c_s1 + c_s2,cmp);
	sort(S + c_s1 + c_s2,S + c_s1 + c_s2 + c_s3,cmp);
	sort(S + c_s1 + c_s2 + c_s3,S + c_s1 + c_s2 + c_s3 + c_s4,cmp);
	printf("%d\n",num);
	for (int i = 0;i < num;i++){
		printf("%s %d %d\n",S[i].id,S[i].de_score,S[i].cai_score);
	}
} 
