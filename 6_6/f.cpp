#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "utility"
#include "set"
using namespace std;
struct Road{
    int from,to;
};
typedef pair<int,int> pi;
int dis[101];
int vis[101];
int bianshu[101][101];
int m[101][101];
struct Road road[4000];
set<pi> tree[101];
int sum[101];
int n,mm;
struct bian{
    int father,son,dis;
};
void bfs(int v)
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<struct bian> q;
    for(int i=1;i<=n;i++){
        if(m[v][i]){
            struct bian tep;
            tep.father=v;
            tep.son=i;
            tep.dis=1;
            q.push(tep);
            tree[v].insert(make_pair(v,i));
        }
    }
    while(!q.empty()){
        struct bian tep=q.front();
        q.pop();
        if(vis[tep.son])
            continue;
        vis[tep.son]=1;
        dis[tep.son]=tep.dis;
        for(int i=1;i<=n;i++){
            if(m[tep.son][i]&&!vis[i]){
                struct bian teptep;
                teptep.father=tep.son;
                teptep.son=i;
                teptep.dis=tep.dis+1;
                q.push(teptep);
                tree[v].insert(make_pair(teptep.father,teptep.son));
            }
        }
    }
}
int bfs2(int v)
{
    int sons=0;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<pi> q;
    q.push(make_pair(v,0));
    while(!q.empty()){
        pi a=q.front();
        q.pop();
        if(vis[a.first])
            continue;
        vis[a.first]=1;sons++;
        dis[a.first]=a.second;
        for(int i=1;i<=n;i++){
            if(m[a.first][i]&&!vis[i]){
                q.push(make_pair(i,a.second+1));
            }
        }
    }
    if(sons==n)
        return 1;
    else
        return 0;
}
int main()
{
    while(scanf("%d %d",&n,&mm)==2){
        memset(bianshu,0,sizeof(bianshu));
        memset(sum,0,sizeof(sum));
        memset(road,0,sizeof(road));
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=mm;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            bianshu[from][to]++;
            bianshu[to][from]++;
            road[i].from=from;
            road[i].to=to;
            m[from][to]=m[to][from]=1;
        }

        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=1;j<=n;j++){
                sum[i]=sum[i]+dis[j];
            }
        }
        for(int kk=1;kk<=mm;kk++){
            int from=road[kk].from;
            int to=road[kk].to;
            if(bianshu[from][to]>1){
                int all=0;
                for(int j=1;j<=n;j++)
                    all=all+sum[j];
                printf("%d\n",all);
                continue;
            }
            m[from][to]=m[to][from]=0;
            int all=0;
            int flag=1;
            for(int j=1;j<=n;j++){
                pi p1=make_pair(from,to);
                pi p2=make_pair(to,from);
                if(tree[j].count(p1)||tree[j].count(p2)){
                    if(bfs2(j))
                    for(int h=1;h<=n;h++){
                        all=all+dis[h];
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
                else{
                    all=all+sum[j];
                }

            }
            if(flag)
                printf("%d\n",all);
            else{
                printf("INF\n");
            }
            m[from][to]=m[to][from]=1;

        }
    }
}
