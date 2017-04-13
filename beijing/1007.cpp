#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "vector"
using namespace std;
typedef long long LL;

int * dp[8];
int fac[9];
int a[10];
queue<int> qq;
void bfs(int n)
{
    int x=0;
    for(int i=1;i<=n;i++){
        x=x*10+i;
    }
    qq.push(x);
    dp[n][x]=0;
    while(!qq.empty()){
        int from=qq.front();
        qq.pop();
        memset(a,0,sizeof(a));
        x=from;
        for(int i=n;i>=1;i--,x/=10)
            a[x%10]=i;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                if(i>1&&(a[i]<a[i-1]||a[i-1]==0))
                {
                    int to=from-fac[n-a[i]];
                    if(dp[n][to]==-1)
                    {
                        qq.push(to);
                        dp[n][to]=dp[n][from]+1;
                    }
                }
                if(i<n&&(a[i]<a[i+1]||a[i+1]==0))
                {
                    int to=from+fac[n-a[i]];
                    if(dp[n][to]==-1)
                    {
                        qq.push(to);
                        dp[n][to]=dp[n][from]+1;
                    }
                }


            }
        }
    }

}
void init()
{
    fac[0]=1;
    for(int i=1;i<=7;i++){
        fac[i]=fac[i-1]*10;
    }
    int x=0;
    for(int i=1;i<=7;i++){
        x=x*10+8;
        dp[i]=new int[x+1];
        memset(dp[i],-1,sizeof(int)*x);
        bfs(i);
    }

}
int main ()
{
    init();
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int x=0;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            for(int j=1;j<=n;j++)
                if(a[i]>=a[j])
                    sum++;
            x+=i*fac[n-sum];
        }
        printf("%d\n",dp[n][x]);

    }
}
