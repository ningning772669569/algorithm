#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "math.h"
using namespace std;
typedef long long LL;
const int maxn=100005;
int n,m;
int num1[maxn];
int num2[maxn];
bool cmp(int a,int b)
{
    return a<b;
}
int main ()
{
    while(scanf("%d %d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            scanf("%d",&num1[i]);
        }
        for(int j=1;j<=m;j++){
            scanf("%d",&num2[j]);
        }
        LL sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum=sum+(i-j)*abs(num1[i]-num2[j]);
            }
        }
        LL sum2=0;
        sort(num1+1,num1+1+n,cmp);
        sort(num2+1,num2+1+m,cmp);
        int len=min(n,m);
        for(int i=1;i<=len;i++){
            sum2+=num1[i]*num2[i]+1;
            //printf("%I64d ",sum2);
        }
        printf("\n%I64d %I64d\n",sum,sum2-1);
    }
}
