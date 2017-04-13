#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "queue"
#define maxn 220
#define INF 0x3f3f3f3f
using namespace std;

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
int g[210][210];
int n,m;
int main ()
{
    edmondkarp e;
    while(scanf("%d%d",&n,&m)==2){
        e.init(m);
        //e.m=n;
        //e.n=m;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]+=c;

        }
        //cout<<"&&&&"<<endl;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j])
                    e.addedge(i,j,g[i][j]);
            }

        }
        //cout<<"&&&&"<<endl;
        int re=e.maxflow(1,m);
        //cout<<"&&&&"<<endl;
        printf("%d\n",re);

    }
}
