/*ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�
����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�
Ӧ�ñ����˵���

�����ʽ��
�����ڵ�һ�и���������N��ȡֵ��(0, 105]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ�������
�Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�

�����ʽ��
��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���

����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������
3 Tom John
*/
#include <cstdio>
struct people{
	char name[6];
	int year,month,day;
}max,min,temp;

int main(){
	int N;
	scanf("%d",&N);
	int i;
	int count = 0;
	int t = 20140906,tt;
	int mmax = 0,mmin = 200000;
	for (i = 0;i < N;i++){
		scanf("%s%d/%d/%d",temp.name,&temp.year,&temp.month,&temp.day);
		//printf("%s %d %d %d",na,y,m,d);
		tt = 10000*temp.year+100*temp.month+temp.day;
		if (t - tt > 2000000) continue;
		else if (tt > t) continue;
		else {
			count++;
			if (t - tt > mmax){
				mmax = t - tt;
				max = temp;
			}
			if (t - tt < mmin){
				mmin = t - tt;
				min = temp;
			}
		}
	}
	if (count == 0) printf("0");
	else printf("%d %s %s",count,max.name,min.name);
}
