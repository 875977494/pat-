/*如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，
很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，
Knut是[0, 29)区间内的整数。

输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1

输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/
#include <cstdio>
int main(){
	int Pb,Pc;
	long long Pa,Aa;
	int Ab,Ac;
	long long P_m,A_m;
	scanf("%lld.%d.%d%lld.%d.%d",&Pa,&Pb,&Pc,&Aa,&Ab,&Ac);
	//printf("%d.%d.%d\n",Pa,Pb,Pc);
	//printf("%d.%d.%d\n",Aa,Ab,Ac);
	P_m = 17 * 29 * Pa + 29 * Pb + Pc;
	A_m = 17 * 29 * Aa + 29 * Ab + Ac;
	int a = 1;
	if (A_m - P_m < 0){
		a = -1;
		long long temp = P_m;
		P_m = A_m;
		A_m = temp;
	}
	long long z_a = (A_m - P_m)/(17*29);
	long long z_b = (A_m - P_m - z_a * 17 * 29)/29;
	long long z_c = A_m - P_m - z_a * 17 * 29 - z_b * 29;
	//printf("%lld\n%lld %lld %lld",A_m - P_m,z_a,z_b,z_c);
	printf("%lld.%lld.%lld",a*z_a,z_b,z_c);
} 

