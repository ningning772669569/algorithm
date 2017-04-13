#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
#include "queue"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn =300;
const int INF=8888888;

struct Edge {
  int from, to, cap, flow;
};

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;    // 边数的两倍
  vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[maxn];        // BFS使用
  int d[maxn];           // 从起点到i的距离
  int cur[maxn];         // 当前弧指针

  void ClearAll(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    while(BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
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
Dinic g;
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
        g.ClearAll(2*n+1);
        re.clear();
        scanf("%d %lf",&n,&maxdis);
        int source=0;
        int tot=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d %d",&x[i],&y[i],&pnum[i],&jnum[i]);
            tot+=pnum[i];
            g.AddEdge(source,i,pnum[i]);
            g.AddEdge(i,i+n,jnum[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)    continue;
                double dis;
                dis=getdis(i,j);
                if(dis<maxdis)
                    g.AddEdge(i+n,j,INF);
            }

        }
        for(int i=1;i<=n;i++){
            g.ClearFlow();
            int t=g.Maxflow(source,i);
            if(t==tot)
                re.push_back(i);
        }
        if(!re.empty()){
            for(vector<int>::size_type j=0;j<re.size();j++){
                printf("%d",re[j]-1);
                if(j<re.size()-1)
                    printf(" ");
            }
        }
        else
            printf("-1");
        printf("\n");
        double dis=getdis(3,2);
        //cout<<"*****"<<dis*dis<<std::endl;
    }


}
