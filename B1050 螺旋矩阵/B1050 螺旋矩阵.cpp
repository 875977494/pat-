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
            if(i*j==N&&(i-j)<min){//在符合条件的数中寻找差最小的数，并记录下来
                min=i-j;
                m=i;
                n=j;
            }
        }   
    }
    int screw[m][n];//用二维数组表示螺旋矩阵
    memset(screw,0,sizeof(screw));
    int i=0,j=0,k=0;
    screw[i][j]=num[k++];//首先为了以后赋值方便先将第一个元素赋值
    while(k<N){     //需要赋值N次
        while(j+1<n&&!screw[i][j+1])    screw[i][++j]=num[k++];//往右，如果小于边界值并且没有赋值过，则赋值
        while(i+1<m&&!screw[i+1][j])    screw[++i][j]=num[k++];//往下，如果小于边界值并且没有赋值过，则赋值
        while(j-1>=0&&!screw[i][j-1])   screw[i][--j]=num[k++];//往左，如果小于边界值并且没有赋值过，则赋值
        while(i-1>=0&&!screw[i-1][j])   screw[--i][j]=num[k++];//往上，如果小于边界值并且没有赋值过，则赋值
    }//至于为什么要用++j，因为如果是j++，往下的时候，j需要减一，造成了后续的繁琐
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j!=0)
                cout<<" ";  //如果不是第一个元素，则元素前面应有空格
            cout<<screw[i][j];
        }       
            cout<<endl;
    }
    return 0;
}
