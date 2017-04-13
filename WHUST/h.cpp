#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "utility"
#include "math.h"
using namespace std;
const int maxn=760;

int x[maxn];
int y[maxn];
int n,m;
struct node{
    int left,right;
    double cost;
};
struct node road[maxn*maxn];
int p[maxn];
int vis[maxn];
int find(int x){return x==p[x]? x:p[x]=find(p[x]);}
void init()
{
    for(int i=1;i<=n;i++){
        p[i]=i;

    }
    memset(vis,0,sizeof(vis));
}
double dis(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int cmp(const struct node &p,const struct node &q)
{
    return p.cost<q.cost;
}
void kruskal(int bian)
{
    //double ans=0;

    for (int i=1;i<=bian;i++)
    {
        int a=find(road[i].left);
        int b=find(road[i].right);
        if(a!=b)
        {
    //ans+=road[i].cost;
            printf("%d %d\n",road[i].left,road[i].right);
            p[a]=b;
        }
    }

}
int main ()
{
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int left,right;
            scanf("%d %d",&left,&right);
            int a=find(left);
            int b=find(right);
            p[a]=b;
            vis[left]=1;
            vis[right]=1;
        }
        int bian=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i)    continue;
                int a=find(i);
                int b=find(j);
                if(a==b)   continue;
                bian++;
                road[bian].left=i;
                road[bian].right=j;
                road[bian].cost=dis(i,j);
            }
        }
        sort(road+1,road+1+bian,cmp);
        kruskal(bian);

    }
}
