#include "algorithm"
#include "cstdio"
#include "queue"
#define MAX 210
#define INF 99999
using namespace std;

bool visited [MAX];
int G[MAX][MAX];
int d[MAX];
pair <int,int> pii;
int main ()
{
    int n,m;
    int x,y,dis;
    int start,end;
    while(scanf("%d %d",&n,&m)){

        priority_queue<pii,vector<pii>,greater<pii> > q;
        memset(visited,o,sizeof(visited));
        memset(G,0,sizeof(G));
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&dis);
            G[x][y]=dis;
        }
        scanf("%d %d",&start,&end);
        for(int i=1;i<=n;i++){
                d[i]=(i==start? 0: INF);
        }
        q.push(make_pai(d[start],start));
        while(!q.empty){
            pii u=q.top;
            q.pop();
            int now=u.second;
            if(visited[now])
                continue;
            visited[now]=true;
            for(int i=1;i<=n;i++){
                if(d[i]>d[now]+G[now][i])
                    d[i]=d[now]+G[now][i];
                q.push(make_pair(d[i],i));
            }
        }
        cout <<d[end] <<std::endl

    }
    return 0;
}
