#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
#include "queue"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn =110;
const int INF=8888888;
struct Edge{
    int from;
    int to;
    int cap;
    int flow;
    Edge(){}
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}

};

struct EdmondsKarp{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];

    void init(int n)
    {
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }

    void Addedge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
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
                int x=Q.front();Q.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge &e =edges[G[x][i]];
                    if(!a[e.to] && e.cap>e.flow){
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t])    break;
            }

        if(!a[t])
            break;
        for(int u=t;u!=s;u=edges[p[u]].from){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        flow+=a[t];
        }
        return flow;
    }
};

int n;
double maxdis;
int pnum[maxn];
int jnum[maxn];
int m[maxn][maxn];
int x[maxn];
int y[maxn];
EdmondsKarp g;
vector<int> re;
double getdis(int v,int u)
{
    double dis;
    dis=sqrt((x[v]-x[u])*(x[v]-x[u])+(y[v]-y[u])*(y[v]-y[u]));
    return dis;
}


int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(m,0,sizeof(m));
        memset(jnum,0,sizeof(jnum));
        memset(pnum,0,sizeof(pnum));
        g.init(n);
        re.clear();
        scanf("%d %lf",&n,&maxdis);
        int source=0;
        int tot=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d %d",&x[i],&y[i],&pnum[i],&jnum[i]);
            tot+=pnum[i];
            g.Addedge(source,i,pnum[i]);
            g.Addedge(i,i+n,jnum[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)    continue;
                double dis;
                dis=getdis(i,j);
                if(dis<maxdis)
                    g.Addedge(i+n,j,INF);
            }

        }
        for(int i=1;i<=n;i++){
            //g.init();
            int t=g.maxflow(source,i);
            if(t==tot)
                re.push_back(i);
        }
        if(!re.empty()){
            for(vector<int>::size_type j=0;j<re.size();j++){
                printf("%d",re[j]);
                if(j<re.size()-1)
                    printf(" ");
            }
        }
        else
            printf("-1");
        printf("\n");
        double dis=getdis(3,2);
        cout<<"*****"<<dis*dis<<std::endl;
    }


}
