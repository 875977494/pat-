/*������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ ���� ���纣����߹����ģ���ʮ�߸�������(Sickle)��һ����¡(Galleon)����ʮ�Ÿ�����(Knut)��һ�����ɣ�
�����ס������ڣ���������Ӧ���ļ�ǮP����ʵ����ǮA�����������дһ��������������Ӧ�ñ��ҵ���Ǯ��

�����ʽ��
������1���зֱ����P��A����ʽΪ��Galleon.Sickle.Knut���������1���ո�ָ�������Galleon��[0, 107]�����ڵ�������Sickle��[0, 17)�����ڵ�������
Knut��[0, 29)�����ڵ�������

�����ʽ��
��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ�������û����Ǯ����ô�����Ӧ���Ǹ�����

��������1��
10.16.27 14.1.28
�������1��
3.2.1

��������2��
14.1.28 10.16.27
�������2��
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

