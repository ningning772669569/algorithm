#include "cstdio"
#include "cstring"
#include "algorithm"
#define MAX 100
#define INF 0xFFFFFF
using namespace std;
int G[MAX][MAX];
int main ()
{
    int n;
    scanf("%d",&n);
    int m;
    int x,y,dis;
    int d[n+1];
    scanf("%d",&m);
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    int mi=INF,pos;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&dis);
        G[x][y]=dis;
        G[y][x]=dis;
    }
    for(int i=1;i<=n;i++){
        if(i==1)
            d[i]=0;
        else
            d[i]=INF;
    }

    for(int i=1;i<=n;i++){
        mi=INF;
        pos=-1;
        for(int j=1;j<n;j++){
            if(!vis[j]&&d[j]<mi){
                pos=j;
                mi=d[j];
            }
        }

    }

}
