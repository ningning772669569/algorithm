#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "vector"
#define INF 0x3f3f3f3f
using namespace std;
struct node {
    int d,u;
    bool operator < (const node &rhs) const {
        return d > rhs.d;
    }
};
int N,M;
int G[35][35];
int tg[35][35];
int vis[35];
int dis[35];
int digkstra(int s)
{
    priority_queue<node> Q;
    for(int i=1;i<=N;i++)   dis[i]=INF;
    dis[s]=0;
    memset(vis,0,sizeof(vis));
    Q.push((node){0,s});
    while(!Q.empty()){
        node x=Q.top();Q.pop();
        int u=x.u;
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=1;i<=N;i++){
            if(u==i)    continue;
            if(dis[i]>dis[u]+tg[u][i]){
                dis[i]=dis[u]+tg[u][i];
                Q.push((node){dis[i],i});
            }
        }
    }
    return dis[N];
}
int main ()
{
    while(scanf("%d %d",&N,&M)==2 && N){
        memset(G,0x3f,sizeof(G));
        for(int i=1;i<=M;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            G[a][b]=G[b][a]=min(G[a][b],c);
        }
        int re=0;
        int flag=0;
        for(int u=2;u<N;u++){
            memcpy(tg,G,sizeof(G));
            for(int i=1;i<=N;i++){
                tg[i][u]=tg[u][i]=INF;
            }
            int tt=digkstra(1);
            if(tt>=INF){
                flag=1;
                break;
            }
            re=max(re,tt);
        }

        if(!flag)
            printf("%d\n",re);
        else
            printf("Inf\n");
    }
}
