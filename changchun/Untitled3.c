#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
using namespace std;
typedef long long LL;
const int maxn=10010;
struct Edge{
    int from,to;
};

int p,m;
int v[maxn];
int vis[maxn];
vector<int> G[maxn],bcc[maxn];
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
stack<Edge> S;


int dfs(int u,int fa)
{
int lowu=pre[u]=++dfs_clock;
int child=0;
for (int i=0;i<G[u].size();i++)
{
int v=G[u][i];
Edge e=(Edge){u,v};
if (!pre[v])
{
S.push(e);
child++;
int lowv=dfs(v,u);
lowu=min(lowu,lowv);
if (lowv>=pre[u])
{
iscut[u]=true;
bcc_cnt++;
bcc[bcc_cnt].clear();
while (1)
{
Edge x=S.top(); S.pop();
if (bccno[x.from]!=bcc_cnt)
{
bcc[bcc_cnt].push_back(x.from);
bccno[x.from]=bcc_cnt;
}
if (bccno[x.to]!=bcc_cnt)
{
bcc[bcc_cnt].push_back(x.to);
bccno[x.to]=bcc_cnt;
}
if (x.from==u && x.to==v) break;
}
}
}
else if (pre[v]<pre[u] && v!=fa)
{
S.push(e);
lowu=min(pre[v],lowu);
}
}
if(fa<0 && child==1) iscut[u]=false;
return lowu;
}

void find_bcc(int n)
{
    for(int i=0;i<maxn;i++)
    {
        bcc[i].clear();
    }
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=bcc_cnt=0;
    for(int i=1;i<=n;i++){
        if(!pre[i])
        dfs(i,-1);
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&p,&m);
        for(int i=1;i<=p;i++){
            G[i].clear();
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=p;i++){
            scanf("%d",&v[i]);
        }
        for(int i=1;i<=m;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            G[l].push_back(r);
            G[r].push_back(l);
        }
        LL sum=0;
        find_bcc(p);
        for(int i=0;i<bcc_cnt;i++){
            if(bcc[i].size()%2==1 && bcc[i].size()!=1){
                for(int j=0;j<=bcc[i].size();j++){
                    int t=bcc[i][j];
                    if(!vis[t]){
                        sum+=v[t];
                        vis[t]=1;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
}
