#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "queue"
#include "utility"
#define MAX 10009
#define INF 100001
using namespace std;
typedef pair <int,int>pi;
int G[MAX][MAX];
int n,m;
bool visited[MAX];
priority_queue<pi,vector<pi>,greater<pi> > q;
int fa[MAX];
int d[MAX];
int main ()
{
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int a,b,l;

        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&a,&b,&l);
            G[a][b]=l;
            G[b][a]=l;
        }
        for(int i=1;i<=n;i++){
            d[i]=(i==1? 0 :INF);
        }
        memset(visited,0,sizeof(visited));
        memset(fa,0,sizeof(fa));
        q.push(make_pair(d[1],1));
        while(!q.empty()){
            pi u=q.top();
            q.pop();
            int x=u.second;
            if(visited[x]){
                continue;
            }
            visited[x]=true;
            for(int e=0;e<n;e++){
                if(G[x][e]){
                if(d[e]>d[x]+G[x][e]){
                    d[e]=d[x]+G[x][e];
                    q.push(make_pair(d[e],e));
                    fa[e]=x;
                }
                }

            }
        }
        int _max=-1*INF;

        for(int aa=n;aa!=1;aa=fa[aa]){

            if(_max<G[aa][fa[aa]])
                _max=G[aa][fa[aa]];
        }
        printf("%.1f\n",(double)((double)d[n]-(double)(_max/2)));
    }
    return 0;
}
