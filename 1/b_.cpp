#include "algorithm"
#include "vector"
#include "cstdio"
#include "utility"
#include <queue>
#include "cstring"
#define MAX 110
using namespace std;
typedef pair<int,int> pi;
priority_queue<pi,vector<pi>,greater<pi> >q;
int G[MAX][MAX];
bool vis[MAX];
int main ()
{
    int T;
    int cost;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        cost=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                G[i][j]=-1;
            }
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            G[x][y]=w;
            G[y][x]=w;

        }
        q.push(make_pair(0,1));
        while(!q.empty()){
            pi u=q.top();
            q.pop();
            if(vis[u.second])
                continue;
            vis[u.second]=true;

            cost+=u.first;
            for(int i=1;i<=m;i++){
                if(G[u.second][i]!=-1&&!vis[i]){
                    q.push(make_pair(G[u.second][i],i));
                }
            }
        }
        printf("%d\n",cost);
    }
    return 0;
}
