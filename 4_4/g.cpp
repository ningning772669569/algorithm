#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;
int num[20005];
int n,k;
int minhei;
int cmp(int a,int b)
{
    return a<b;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&k);
        minhei=1000000001;
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        sort(num+1,num+n+1,cmp);
        for(int i=1;i<=n-k+1;i++){
            int tep=abs(num[i+k-1]-num[i]);
            minhei=min(minhei,tep);
        }
        printf("%d\n",minhei);
    }
}
