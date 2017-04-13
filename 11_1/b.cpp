#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
#include "set"
#include "map"
using namespace std;
const int maxn=109;
int N,M;
int vis[maxn];
vector<int> G[maxn];
vector<int> point;
struct CUT_V
{
static const int maxn=10000+10;
int dfs_clock,low[maxn],n,m,pre[maxn],sumcut;
vector<int>group[maxn];
bool iscut[maxn];
void init()
{
for (int i=0;i<=n;i++) group[i].clear();
memset(iscut,0,sizeof(iscut));
memset(pre,0,sizeof(pre));
sumcut=0; dfs_clock=0;
}
void addedge(int u,int v)
{
group[u].push_back(v);
group[v].push_back(u);
}
int dfs(int u,int fa)
{
int lowu=pre[u]=++dfs_clock;
int child=0;
for (int i=0;i<group[u].size();i++)
{
int v=group[u][i];
if(!pre[v])
{
child++;
int lowv=dfs(v,u);
lowu=min(lowu,lowv);
if (lowv>=pre[u]) iscut[u]=true;
}
else if(pre[v]<pre[u] && v!=fa) lowu=min(lowu,pre[v]);
}
if (fa==-1 && child==1) iscut[u]=false;
low[u]=lowu;
return lowu;
}
int get_sum()
{

for(int i=1;i<=109;i++) if(!pre[i])dfs(i,-1);
for (int i=1;i<=n;i++) if (iscut[i]) sumcut++;
return sumcut;
}
};
void dfs(int u)
{
    vis[u]=1;
    point.push_back(u);
    for(int i=0;i<G[u].size();i++){
        if(!vis[G[u][i]])
            dfs(G[u][i]);
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        CUT_V cut;
        cut.init();
        for(int i=0;i<maxn;i++){
            G[i].clear();
        }
        int re=0;
        scanf("%d%d",&N,&M);
        for(int i=1;i<=M;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            cut.addedge(u,v);
        }
        cut.get_sum();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                point.clear();
                dfs(i);
                if(point.size()%2==0){
                    int tep=point.size()/2;

                    int num1=0;
                    int num2=0;
                    vector<int> a;
                    for(int i=0;i<point.size();i++){
                        int v=point[i];
                        if(G[v].size()==tep){
                            num2++;
                            a.push_back(v);
                        }
                        if(G[v].size()==tep-1)
                            num1++;

                    }
                    if(num1==point.size()-2 && num2==2 && cut.iscut[a[0]] &&cut.iscut[a[1]]){
                        re++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",t,re);

    }
}
