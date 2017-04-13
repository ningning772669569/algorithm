#include "cstdio"
#include "cstring"
#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"
#define MAX 4004
using namespace std;
struct Edge{
    int from,to;
    Edge(int u,int v):from(u),to(v){}
};
typedef struct Edge edge;
int N;
int M;
int dfs_clock;
int low[MAX];
int pre[MAX];
stack<edge> s;
bool is_cut[MAX];
vector<int> g[MAX];
//vector
int dfs(int u,int fa)
{
    int child=0;
    int lowv;
    int louwu=pre[u]=++dfs_clock;
    for(int i=0;i<g[u].size();i++){
        v=g[u][i];
        if(!pre[v]){
            child++;
            pre[v]=1;
            edge e(u,v);
            lowv=dfs(v,u);
            lowu=min(lowv,lowu);
            if(pre[u]<lowv){

            }
            else {

            }
        }
        else {
            if(pre[v]<pre[u]&&v!=fa)    lowu=min(lowu,pre[v]);
        }
    }
}
int main ()
{
    while(~scanf("%d",&N)){
        if(!N)
            break;
        M=0;
        int dfs_clock=0;
        memset(low,0,sizeof(low));
        memset(pre,0,sizeof(pre));
        memset(is_cut,0,sizeof(is_cut));
        int from,to;
        for(int i=1;i<=N;i++){
            scanf("%d %d",&from,&to);
            M=max(from,M);
            M=max(to,M);
            g[from].push_back(to);
            g[to].push_back(from);
        }

    }
}
