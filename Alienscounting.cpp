#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "stack"
using namespace std;
typedef long long LL;
const int maxn=1010;


const int MOD=1e9+7;

struct Edge{
    int from,to;
};

int N,M;
vector<int> G[maxn];
vector<int> g[maxn];
vector<int> bcc[maxn];
int f[maxn];
vector<int> f2[maxn];

int low[maxn];
int pre[maxn];
int iscut[maxn];
int bccno[maxn];
int vis[maxn];
int bcc_cnt,dfs_clock;
stack<Edge> S;
int num[maxn];
int dfsid;

void init ()
{

    for(int i=0;i<N;i++){
        G[i].clear();
        g[i].clear();
        bcc[i].clear();
    }
    memset(vis,0,sizeof(vis));

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
    for(int i=1;i<=n;i++){
        if(!pre[i]){
            dfs(i,-1);
        }
    }

}
int dd(int u)
{
    if(g[u].size()==0){
        num[1]++;
        return 1;

    }
    else{
        int MAX=0;
        for(int i=0;i<g[u].size();i++){
            int tep=dd(g[u][i]);
            MAX=max(MAX,tep);
        }
        num[MAX+1]++;
        return MAX+1;
    }
}

int pow(int n)
{
    if(n==1)
    return 2;
    if(n==0)
    return 1;
    int a=pow(n/2);
    if(n&1)
        return (2*(a*a)%MOD)%MOD;
    else{
        return  (a*a)%MOD;
    }
}
int getnum(int n)
{
    int a=pow(n);
    return a-1;
}
int main ()
{

    set<int> free;
    while(scanf("%d%d",&N,&M)==2){
        init();
        free.clear();
        int notnum=0;
        for(int i=1;i<=M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            vis[a]=vis[b]=1;
            G[b].push_back(a);
        }
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                free.insert(i);
                notnum++;
            }
        }
        memset(vis,0,sizeof(vis));
        find_bcc(N);
        for(int i=1;i<=N;i++)
            f[i]=i;
        for(int i=1;i<=bcc_cnt;i++){
            if(bcc[i].size()>=3){
                for(int j=0;j<bcc[i].size();j++)
                    f[bcc[i][j]]=bcc[i][0];
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<G[i].size();j++){
                int a=i;
                int b=G[i][j];
                if(f[a]==f[b])
                    continue;
                g[f[a]].push_back(f[b]);
            }
        }
        memset(vis,0,sizeof(vis));
        vector<int> re;
        for(int i=1;i<=N;i++){
            if(!vis && !free.count(i)){
                memset(num,0,sizeof(num));
                int hei=dd(i);
                int sum=0;
                for(int i=1;i<=hei;i++){
                    sum=(sum+getnum(num[i]))%MOD;

                }
                re.push_back(sum);
            }
        }
        LL result=1;
        for(int i=0;i<re.size();i++){
            result=(result*re[i])%MOD;
        }
        result=(result*pow(notnum))%MOD;
        cout<<result<<endl;
    }

}
