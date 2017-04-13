#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=1000009;
int num[maxn];
int N;
int t;
int T;
void solve()
{
    for(int i=1;i<=N;i++){
        scanf("%d",&num[i]);
    }
    LL tepsum=0;
    LL sum=0;
    int from=1,to=-1;
    for(int i=1;i<=N;i++){
        tepsum+=num[i];
        if(tepsum>sum){
            to=i;
            sum=tepsum;
        }
        if(tepsum<0)
            tepsum=0;
    }
    tepsum=0;
    if(to!=-1)
    for(int i=to;i>=1;i--){
        tepsum+=num[i];
        if(tepsum==sum){
            from=i;
        }
    }
    else{
        int tt=-1500;
        for(int i=N;i>=1;i--)
        if(num[i]>tt){
            sum=tt=num[i];
            to=from=i;
        }
    }
    printf("Case %d:\n",t);
    printf("%I64d %d %d\n",sum,from,to);
    if(t<T)
    printf("\n");
}
int main ()
{

    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&N);
        solve();
    }
}
