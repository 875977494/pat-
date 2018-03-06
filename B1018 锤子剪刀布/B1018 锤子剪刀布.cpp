/*
大家应该都会玩“锤子剪刀布”的游戏：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大

输入格式：
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，
第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，
则输出按字母序最小的解。
输入样例：
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
输出样例：
5 3 2
2 3 5
B B
*/
#include <cstdio>
int panding(char a,char b);
int max(int *a);
int main(){
	int N; // C代表锤子，J代表剪刀，B代表布  先甲后乙  胜、平、负
	int x;
	char aa,bb;
	int a[3] = {0,0,0},b[3] = {0,0,0},ac[3]= {0,0,0},bc[3]= {0,0,0}; 
	int c1,c2;
	scanf("%d",&N);
	for (int i = 0;i < N;i++){
		getchar(); // scanf之后要用getchar接一下回车 
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
