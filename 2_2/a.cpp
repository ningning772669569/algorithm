#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
char str[1005][32];
bool vis[1005][1005];
int p[1005];
int m,n;
int maxdis;
int bianshu;
struct Road{
    int left,right,cost;
}road[1000000];
bool cmp(const struct Road &p,const struct Road &q)
{
    return p.cost<q.cost;
}
int _find(int x)
{
    return x==p[x]?x:p[x]=_find(p[x]);
}
void init()
{
    maxdis=0;
    bianshu=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
}
int compair(char * a,char * b)
{
    int Max=0;
    for(int i=0;i<m;i++){
        if(abs(a[i]-b[i])>Max)
            Max=abs(a[i]-b[i]);
    }

    return Max;
}
void kruskal()
{

    for (int i=0;i<bianshu;i++)
    {
        int x=_find(road[i].left);
        int y=_find(road[i].right);
        if(x!=y)
        {
            maxdis=max(road[i].cost,maxdis);
            p[x]=y;
        }
    }

}
int main ()
{
    while (scanf("%d %d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            scanf("%s",str[i]);
        }
        init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                if(vis[i][j]||vis[j][i]){
                    continue;
                }
                int tep;
                tep=compair(str[i],str[j]);
                vis[i][j]=vis[j][i]=true;
                road[bianshu].left=i;
                road[bianshu].right=j;
                road[bianshu].cost=tep;
                bianshu++;

            }
        }
        sort(road,road+bianshu,cmp);
        kruskal();
        printf("%d\n",maxdis);

    }
    return 0;
}

