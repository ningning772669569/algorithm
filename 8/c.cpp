#include "cstdio"
#include "iostream"
#include "cstring"
#include "vector"
#include "algorithm"
#define MAX 34
#define N (MAX*MAX)
using namespace std;
int m,n,k;
int Map[MAX][MAX];
int visited[N];
int cx[MAX*MAX];
int cy[MAX*MAX];
bool edge[N][N];
vector<int> groupx,groupy;

int path(int u)
{
    int v;
    for(vector<int>::size_type a=0;a<groupy.size();a++)
    {
        v=groupy[a];
        if(edge[u][v]&&!visited[v])
	           {
	               visited[v]=1;
	              if(cy[v]==-1||path(cy[v]))//如果y集合中的v元素没有匹配或者是v已经匹配，但是从cy[v]中能够找到一条增广路
	              {
                    cx[u]=v; //找到增广路，修改匹配M
                    cy[v]=u;
	                  return 1;
	               }
	           }
    }
    return 0;
}
int maxmatch()
{
    int res=0;
    memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
    int i;
    for(vector<int>::size_type a=0;a<groupx.size();a++){
        i=groupx[a];
        if(cx[i]==-1)
        {
            memset(visited,0,sizeof(visited));
            res+=path(i);
        }
    }
    return res;
}

int main ()
{
    while(scanf("%d %d",&m,&n)==2){
        int posi,posj;
        scanf("%d",&k);
        if((m*n-k)%2){
            printf("NO\n");
            continue;
        }
        groupx.clear();
        groupy.clear();
        memset(Map,0,sizeof(Map));
        memset(visited,0,sizeof(visited));
        memset(cx,0,sizeof(cx));
        memset(cy,0,sizeof(cy));
        memset(edge,0,sizeof(edge));
        for(int i=1;i<=k;i++){
            scanf("%d %d",&posi,&posj);
            Map[posi][posj]=-1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(Map[i][j]==-1) continue;
                if((((i-1)*j+j)%2==1)){
                    groupx.push_back((i-1)*j+j);
                }
                else{
                    groupy.push_back((i-1)*j+j);
                }
                if(i-1>0&&Map[i-1][j]!=-1){
                    edge[(i-1)*j+j][(i-2)*j+j]=1;
                }
                if(i+1<=m&&Map[i+1][j]!=-1){
                    edge[(i-1)*j+j][i*j+j]=1;
                }
                if(j-1>0&&Map[i][j-1]!=-1){
                    edge[(i-1)*j+j][(i-1)*j+j-1]=1;

                }
                if(j+1<=n&&Map[i][j+1]!=-1){
                    edge[(i-1)*j+j][(i-1)*j+j+1]=1;
                }
            }
        }
        int result =maxmatch();
        printf("%d\n",result);
        if((result*2)==(m*n-k))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
