#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=100010;
struct edge{
    int from,to;
};
int N,M;
vector<pii> G[maxn];
vector<int> g[maxn];
int pre[maxn];
int low[maxn];
int iscut[maxn];
int vis[maxn];
int maxv[maxn];
int newid[maxn];
int newmax[maxn];
edge E[maxn];
int re[maxn];
int dfsid=0;

void init()
{
    for(int i=1;i<=N;i++){
        G[i].clear();
    }
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(iscut,0,sizeof(iscut));
    memset(vis,0,sizeof(vis));
    dfsid=0;
}
int dfs1(int u,int fa)
{
    int lowu;
    int childs=0;
    pre[u]=lowu=++dfsid;
    for(int i=0;i<G[u].size();i++){
        pii t=G[u][i];
        int v=t.first;
        if(v!=fa && !pre[v]){
            childs++;
            int lowv=dfs1(v,u);
            if(lowv>=pre[u])
                iscut[t.second]=1;
            lowu=min(lowu,lowv);
        }
        else if(v!=fa && pre[v]<pre[u])
            lowu=min(lowu,pre[v]);


    }
    ///if(childs==0)
        ///iscut[G[u][0].second]=1;  这里是不必要的因为在if(lowv>=pre[u])  iscut[t.second]=1;已经包含进去了
    low[u]=lowu;
    return lowu;
}

void dfs2(int u,int idx)
{
    vis[u]=1;
    maxv[u]=u;
    newid[u]=idx;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].first;
        if(!vis[v] && !iscut[G[u][i].second]){
            dfs2(v,idx);
            maxv[u]=max(maxv[u],maxv[v]);
        }
    }
}

int dfs3(int u,int fa)
{
    pre[u]=++dfsid;
    re[u]=newmax[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v != fa){
            dfs3(v,u);
            re[u]=max(re[u],re[v]);
        }
    }
}
void BCC_bridge()
{
    int partsnum=0;
    dfsid=0;
    dfs1(1,-1);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            partsnum++;
            dfs2(i,partsnum);
        }
    }
    for(int i=1;i<=N;i++){
        g[i].clear();
    }
    for(int i=1;i<=M;i++){
        if(iscut[i]){
            int a=E[i].from;
            int b=E[i].to;
            g[newid[b]].push_back(newid[a]);
            g[newid[a]].push_back(newid[b]);
        }
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&N,&M);
        init();
        for(int i=1;i<=M;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(make_pair(b,i));
            G[b].push_back(make_pair(a,i));
            E[i].from=a;
            E[i].to=b;
        }
        BCC_bridge();
        memset(newmax,0,sizeof(newmax));
        for(int i=1;i<=N;i++){
            newmax[newid[i]]=max(newmax[newid[i]],i);
        }
        for(int i=1;i<=N;i++){
            if(newmax[i]==N){
                memset(pre,0,sizeof(pre));
                dfsid=0;
                dfs3(i,-1);
                break;
            }
        }
        for(int i=1;i<=M;i++){
            int from=newid[E[i].from];
            int to=  newid[E[i].to];
            if(from==to)
                printf("0 0\n");
            else{
                if(pre[from]<pre[to])
                    swap(from,to);
                printf("%d %d\n",re[from],re[from]+1);
            }
        }
    }
    //return 0;
}
