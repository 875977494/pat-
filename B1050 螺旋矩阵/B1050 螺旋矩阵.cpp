#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    int num[N+5];
    for(int i=0;i<N;i++)
        cin>>num[i];
    sort(num,num+N,greater<int>());
    int m=0,n=0,min=N;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            if(i*j==N&&(i-j)<min){//�ڷ�������������Ѱ�Ҳ���С����������¼����
                min=i-j;
                m=i;
                n=j;
            }
        }   
    }
    int screw[m][n];//�ö�ά�����ʾ��������
    memset(screw,0,sizeof(screw));
    int i=0,j=0,k=0;
    screw[i][j]=num[k++];//����Ϊ���Ժ�ֵ�����Ƚ���һ��Ԫ�ظ�ֵ
    while(k<N){     //��Ҫ��ֵN��
        while(j+1<n&&!screw[i][j+1])    screw[i][++j]=num[k++];//���ң����С�ڱ߽�ֵ����û�и�ֵ������ֵ
        while(i+1<m&&!screw[i+1][j])    screw[++i][j]=num[k++];//���£����С�ڱ߽�ֵ����û�и�ֵ������ֵ
        while(j-1>=0&&!screw[i][j-1])   screw[i][--j]=num[k++];//�������С�ڱ߽�ֵ����û�и�ֵ������ֵ
        while(i-1>=0&&!screw[i-1][j])   screw[--i][j]=num[k++];//���ϣ����С�ڱ߽�ֵ����û�и�ֵ������ֵ
    }//����ΪʲôҪ��++j����Ϊ�����j++�����µ�ʱ��j��Ҫ��һ������˺����ķ���
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j!=0)
                cout<<" ";  //������ǵ�һ��Ԫ�أ���Ԫ��ǰ��Ӧ�пո�
            cout<<screw[i][j];
        }       
            cout<<endl;
    }
    return 0;
}
