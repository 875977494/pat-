/*����һ�����������У���������p������������е����ֵ��M����Сֵ��m����� M <= m * p���������������������С�

���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�

�����ʽ��

�����һ�и�������������N��p������N��<= 105����������������ĸ�����p��<= 109���Ǹ����Ĳ������ڶ��и���N����������ÿ����������109��

�����ʽ��

��һ�������������ѡ����ٸ����������������һ���������С�

����������
10 8
2 3 20 4 5 1 6 7 8 9
���������
8
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main(){
	int N,p;
	scanf("%d%d",&N,&p);
	int a[maxn];
	for (int i = 0;i < N;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,a + N);
	int len = 1;
	for (int i = 0;i < N;i++){
		int temp = upper_bound(a + i + 1,a + N,(long long)a[i] * p) - a;
		len = max(temp - i,len);
	}
	printf("%d",len);
	return 0;
}
