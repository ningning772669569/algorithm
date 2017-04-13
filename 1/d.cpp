#include "cstdio"
#include "algorithm"
#include "cstring"
#include "stack"
using namespace std;
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
 int ans=dfs(1,-1);
 for (int i=1;i<=n;i++) if (iscut[i]) sumcut++;
 return sumcut;
 }
};
int main ()
{

}
