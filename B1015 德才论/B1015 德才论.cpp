/*宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，
君子而与之，与其得小人，不若得愚人。”
现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），
为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也
按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：
输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。
某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
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
