/*输入格式：
 每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。
 输出格式：
 如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。
 输入样例1：
 ppRYYGrrYBR2258
 YrR8RrY
 输出样例1：
 Yes 8
 输入样例2：
 ppRYYGrrYB225
 YrR8RrY
 输出样例2：
 No 2*/

#include <cstdio>
#include <cstring>
const int maxn = 10000;
int main(){
    char c1[1001],c2[1001];
    int a[maxn] = {0};
    gets(c1);
    gets(c2);
    int len = strlen(c2);
    for (int i = 0;c1[i] != '\0';i++){
        a[c1[i]]++;
    }
    /*for (int i = 0;i < maxn;i++){
        printf("%d ",a[i]);
    }*/
    int un = 0, c = 0;
    for (int i = 0;c2[i] != '\0';i++){
        if (a[c2[i]] > 0){
            c++;
            a[c2[i]]--;
        }
        else if (a[c2[i]] <= 0) un++;
    }
    int sum = 0;
    for (int i = 0; i < maxn;i++){
        sum += a[i];
    }
    if (c == len) {
        printf("Yes %d",sum);
    }
    else if (c < len){
        printf("No %d",un);
    }
}
