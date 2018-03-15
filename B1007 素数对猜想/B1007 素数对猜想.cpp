/*让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。
 “素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int isPrime(int a);
int main(){
    int N;
    vector<int> prime;
    scanf("%d",&N);
    int count = 0;
    for (int i = 1;i <= N;i++){
        if (isPrime(i) == 1){
            prime.push_back(i);
        }
    }
    for (int i = 0; i < prime.size();i++){
        //printf("%d ",prime[i]);
        if ((prime[i+1] - prime[i]) == 2) count++;
        else continue;
    }
    printf("%d\n",count);
}

int isPrime(int a){
    if (a <= 1) return 0;
    if (a == 2) return 1;
    int i;
    for (i = 2;i <= sqrt(a);i++){
        if (a % i == 0) return 0;
        else continue;
    }
    return 1;
}
