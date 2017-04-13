#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
using namespace std;
const int maxn=1010;
int N,M;
int si[maxn];
int pi[maxn];
int ei[maxn];

struct edge{
    int from,to,cap,flow;
    edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}

};
struct edmondkarp{
    int n,m;
    vector<edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];
    void init(int n){
        for(int i=0;i<=n;i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from,int to,int cap)
    {
        edges.push_back(edge(from,to,cap,0));
        edges.push_back(edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int maxflow(int s,int t)
    {
        int flow=0;
        while(1){
            memset(a,0,sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s]=INF;
            while(!Q.empty()){
                int x=Q.front(); Q.pop();
                for(int i=0;i<G[x].size();i++){
                    edge &e=edges[G[x][i]];
                    if(!a[e.to] && e.cap>e.flow){
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t])    break;
            }
            if(!a[t])   break;
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        sacnf("%d%d",&N,&M);
        int sum=0;
        for(int i=1;i<=N;i++){
            scanf("%d%d%d",pi+i,si+i,ei+i);
            sum+=pi[i];
        }
        edmondkarp e;
        e.init();
        for(int i=1;i<=N;i++)
            e.addedge(0,i,pi[i]);
        for(int i=1;i<=N;i++){
            for(int j=si[i];j<=ei[i];j++){
                e.addedge(i,j+500,1);
            }
        }
        for(int i=501;i<=1000;i++)
            e.addedge(i,1001,M);
        int re=e.maxflow(0,1001);
        if(re==sum)
            printf("Yes\n\n");
        else
            printf("No\n\n");

    }


}
