#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "queue"
using namespace std;
typedef long long LL;
const int maxn=1010;
struct goodies{
    int p,j;
};
struct goodies g[maxn];
int dp[maxn][maxn];
int cost[maxn][maxn];
int n;
char name[100];
int sum;
bool cmp(const goodies & p,const goodies & q)
{
    if(p.p!=q.p){
        return p.p>q.p;
    }
    else
        return p.j<q.j;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(dp,0,sizeof(dp));
        memset(cost,0,sizeof(cost));
        sum=0;
        scanf("%d",&n);
        scanf("%s",name);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&g[i].p,&g[i].j);

            sum+=g[i].p;
        }
        sort(g+1,g+1+n,cmp);
        int start=1;
        if(name[0]=='P'){
            start=2;
        }
        int cur=0;
        for(int i=start;i<=n;i++){
            cur++;
            for(int j=1;j<=(cur+1)/2;j++){
                dp[cur][j]=max(dp[cur-1][j-1]+g[i].j,dp[cur-1][j]);
                if(dp[cur-1][j-1]+g[i].j>dp[cur-1][j]){
                    cost[cur][j]=cost[cur-1][j-1]+g[i].p;
                }
                else if(dp[cur-1][j-1]+g[i].j<dp[cur-1][j]){
                    cost[cur][j]=cost[cur-1][j];
                }
                else{

                    cost[cur][j]=min(cost[cur-1][j],cost[cur-1][j-1]+g[i].p);
                }
            }
        }

        printf("%d %d\n",sum-cost[cur][(cur+1)/2],dp[cur][(cur+1)/2]);

    }
    return 0;
}
