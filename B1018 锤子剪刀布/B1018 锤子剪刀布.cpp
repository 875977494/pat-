/*
���Ӧ�ö����桰���Ӽ�����������Ϸ��
�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����

�����ʽ��
�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B����������
��1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��
�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ��
���������ĸ����С�Ľ⡣
����������
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
���������
5 3 2
2 3 5
B B
*/
#include <cstdio>
int panding(char a,char b);
int max(int *a);
int main(){
	int N; // C�����ӣ�J���������B����  �ȼ׺���  ʤ��ƽ����
	int x;
	char aa,bb;
	int a[3] = {0,0,0},b[3] = {0,0,0},ac[3]= {0,0,0},bc[3]= {0,0,0}; 
	int c1,c2;
	scanf("%d",&N);
	for (int i = 0;i < N;i++){
		getchar(); // scanf֮��Ҫ��getchar��һ�»س� 
		scanf("%c %c",&aa,&bb);
		x = panding(aa,bb);
		if (x == 1){
			a[0]++;
			b[2]++;
			if (aa == 'B')
				ac[0]++;
			else if (aa == 'C') 
				ac[1]++;
			else 
				ac[2]++;
		}
		else if (x == 0){
			a[1]++;
			b[1]++;
		}
		else {
			a[2]++;
			b[0]++;
			if (bb == 'B')
				bc[0]++;
			else if (bb == 'C') 
				bc[1]++;
			else 
				bc[2]++;
		}
	}
	c1 = max(ac);
	c2 = max(bc);
	printf("%d %d %d\n",a[0],a[1],a[2]);
	printf("%d %d %d\n",b[0],b[1],b[3]);
	if (c1 == 0) printf("B ");
	else if (c1 == 1) printf("C ");
	else printf("J ");
	if (c2 == 0) printf("B");
	else if (c2 == 1) printf("C");
	else printf("J");
}

int panding(char a,char b){
	if ((a == 'C' && b == 'J')||(a == 'J' && b == 'B')||(a == 'B' && b == 'C'))
		return 1;
	else if ((a == 'C' && b == 'C')||(a == 'J' && b == 'J')||(a == 'B' && b == 'B'))
		return 0;
	else //if ((a == 'C' && b == 'J')||(a == 'J' && b == '')
		return -1;
}

int max(int *a){
	int i,c;
	int max = a[0];
	for (i = 0,c = 0;i < 3;i++){
		if (a[i] > max){
			max = a[i];
			c = i;
		}
	}
	return c;
}
