#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
#include "utility"
using namespace std;
typedef long long LL;
typedef pair<int,LL> pii;
const int maxn=10010;

struct Edge{
    int from,to;
};

int p,m;
long long  v[maxn];
int vis[maxn];
int is[maxn];
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int> G[maxn],bcc[maxn];
stack<Edge> S;


int dfs(int u,int fa)
{
    if(G[u].empty())
    {
        vis[u]=1;
        return 0;
    }
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
            if (lowv>pre[u])
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
    while(!S.empty())
        S.pop();
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=bcc_cnt=0;
    for(int i=1;i<=n;i++){
        if(!pre[i]){
        while(!S.empty())
            S.pop();
        dfs(i,-1);
        }
    }

}
void DFS(int u)
{

    if(is[u])
        return ;
    if(vis[u])
        return ;
    vis[u]=1;
    if(G[u].empty())
        return;
    for(int i=0;i<G[u].size();i++){
        int son=G[u][i];
        if(!vis[son]&&!is[son])
            DFS(son);
    }


}
pair<int,long long> dd(int u,int fa)
{
    if(vis[u])
        return pii(0,0);
    vis[u]=1;
    int childs=0;
    LL tepsum=0;
    for(int i=0;i<G[u].size();i++){
        int t=G[u][i];
        if(!vis[t]&&t!=fa){

            pii tep=dd(t,u);
            childs+=tep.first;
            tepsum+=tep.second;
        }

    }
    if(childs==0)
        return pii(1,v[u]);
    return pii(childs+1,tepsum+v[u]);

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
        LL sum=0;
        for(int i=1;i<=p;i++){
            scanf("%I64d",&v[i]);
        }
        for(int i=1;i<=m;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            G[l].push_back(r);
            G[r].push_back(l);
        }
        if(p==1||m==0){
            printf("0\n");
            continue;
            }
        find_bcc(p);
        memset(is,0,sizeof(is));
        for(int i=1;i<=bcc_cnt;i++){
           /* for(int j=0;j<bcc[i].size();j++){
                printf("%d ",bcc[i][j]);
            }
            printf("\n");
            */
            if(bcc[i].size()>2){

                for(int j=0;j<bcc[i].size();j++){
                    int point =bcc[i][j];
                    is[point]=1;

                }

            }

        }
        for(int i=1;i<=p;i++){
            if(G[i].size()<=1){
                DFS(i);
            }
        }
        sum=0;
        for(int i=1;i<=p;i++){
            if(!vis[i]){
                pii tt;
                tt=dd(i,-1);
                if(tt.first&1)
                    sum+=tt.second;
            }
        }
        printf("%I64d\n",sum);

    }
    return 0;
}
