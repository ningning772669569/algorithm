#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "queue"
#include "utility"
#define MAX 1000
#define INF 10000001
using namespace std;
int anc[MAX][11];
int fa[MAX];
int times[MAX];
vector<int> tree[MAX];
int m,n;
int dep[MAX];
void RMQ(int n)
{
    memset(anc,0,sizeof(anc));
    for(int i=1;i<=n;i++){
        anc[i][0]=fa[i];
    }
    for(int k=1;k<=10;k++){
        for(int v=1;v<=n;v++){
            anc[v][k]=anc[anc[v][k-1]][k-1];
        }
    }
}
int swim (int x,int H)
{
    for(int i=0;H>0;i++){
        if(H&1){
            x=anc[x][i];
            H=H>>1;
        }
    }
    return x;
}
int LCA (int u,int v)
{
    int k;
    if(dep[u]>dep[v]) swap(u,v);
    v=swim(v,dep[v]-dep[u]);
    if(u==v)
        return v;
    while (1){
        for (k=0;anc[u][k]!=anc[v][k];k++);
        if (k==0) return anc[u][0];
        u=anc[u][k-1];
        v=anc[v][k-1];
    }

}
void dfs(int u,int _dep)
{
    dep[u]=_dep;
    for(int i=0;i<tree[u].size();i++){
        dfs(tree[u][i],_dep+1);
    }
}
int main ()
{
    int N;
    while( scanf("%d",&N)){
    memset(fa,-1,sizeof(fa));
    int root;

    for(int i=1;i<=N;i++){
        int num,nodes;
        scanf("%d:(%d)",&num,&nodes);
        if(i==1) root=num;
        for(int j=1;j<=nodes;j++){
            int pos;
            scanf("%d",&pos);
            fa[pos]=num;
            tree[num].push_back(pos);
        }

    }
    dfs(root,1);
    RMQ(N);
    int t;

    int tep;
    int _a,_b;
    scanf("%d",&t);
    for(int i=1;i<t;i++){

        scanf(" (%d %d) ",&_a,&_b);
        tep=LCA(_a,_b);
        times[tep]++;
    }
    scanf(" (%d %d)",&_a,&_b);
    tep=LCA(_a,_b);
    times[tep]++;
    for(int i=1;i<=N;i++){
        if(times[i])
            printf("%d:%d\n",i,times[i]);
    }
    }
    return 0;
}
