#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
using namespace std;
const int maxn=5050;

struct Edge{
    int from,to;
};
int N,M,Q;
vector<int> G[maxn];
vector<int> bcc[maxn];
int f1[maxn];
vector<int> f2[maxn];
int vis[maxn];
int low[maxn];
int pre[maxn];
int iscut[maxn];
int bccno[maxn];
int bcc_cnt,dfs_clock;
stack<Edge> S;
int dfsid;
void init ()
{
    for(int i=0;i<N;i++){
        G[i].clear();
        bcc[i].clear();
    }
}


void dfs1(int u,int partsnum)
{
    vis[u]=1;
    f1[u]=partsnum;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v]){
            dfs1(v,partsnum);
        }
    }
}


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
    while(!S.empty())
        S.pop();
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    memset(vis,0,sizeof(vis));
    dfs_clock=bcc_cnt=0;
    for(int i=0;i<n;i++){
        if(!pre[i]){
            dfs(i,-1);
        }
    }

}
int main ()
{
    int caseid=0;
    while(scanf("%d %d %d",&N,&M,&Q)==3){
        if(N==0)
            break;
        init();
        for(int i=1;i<=M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        memset(vis,0,sizeof(vis));
        int partsnum=0;
        for(int i=0;i<N;i++){
            if(!vis[i])
                dfs1(i,++partsnum);
        }
        find_bcc(N);
        for(int i=0;i<=N;i++){
            f2[i].clear();
        }
        for(int i=1;i<=bcc_cnt;i++){
            for(int k=0;k<bcc[i].size();k++)
            {
                int u=bcc[i][k];
                f2[u].push_back(i);

            }

        }
        printf("Case %d:\n",++caseid);
        for(int i=1;i<=Q;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            if(f1[from]!=f1[to])
                printf("zero\n");
            else{
                    int flag=0;
                    for(int k=0;k<f2[from].size();k++){
                        for(int j=0;j<f2[to].size();j++){
                            if(f2[from][k]==f2[to][j]){
                                int num=f2[from][k];
                                if(bcc[num].size()>2)
                                {
                                    flag=1;
                                    break;
                                }

                            }

                        }
                    }
                    if(flag)
                        printf("two or more\n");
                    else
                        printf("one\n");


            }
        }

    }
    return 0;
}
