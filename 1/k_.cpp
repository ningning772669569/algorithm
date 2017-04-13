#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "queue"
#include "utility"
#define MAX 1010
#define INF 10000001
using namespace std;
int anc[MAX][30];
int fa[MAX];
int times[MAX];


int dep[MAX];
void RMQ(int n)
{
    memset(anc,0,sizeof(anc));
    for(int i=1;i<=n;i++){
        anc[i][0]=fa[i];
    }
    for(int k=1;k<=20;k++){
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

        }
         H=H>>1;
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

int main ()
{
    int N;
    cin >>N;
    memset(fa,0,sizeof(fa));

    for(int i=1;i<=N;i++){
        int num,nodes;
        scanf("%d:(%d)",&num,&nodes);

        for(int j=1;j<=nodes;j++){
            int pos;
            scanf("%d",&pos);
            fa[pos]=num;

        }

    }
    memset(dep,0,sizeof(dep));
    for(int i=1;i<=N;i++){
        int x=i;
        while(fa[x]){
            dep[i]++;
            x=fa[x];
        }
    }
    RMQ(N);
    int t;
    memset(times,0,sizeof(times));
    int tep;
    int _a,_b;
    scanf("%d",&t);
    for(int i=1;i<t;i++){
        char c;
        for(c=' ';c!='(';scanf("%c",&c));
        scanf("%d %d",&_a,&_b);
        for(c=' ';c!=')';scanf("%c"),&c);
        tep=LCA(_a,_b);
        printf("%d\n",tep);
        times[tep]++;

    }

    for(int i=1;i<=N;i++){
        if(times[i])
            printf("%d:%d\n",i,times[i]);
    }

    return 0;
}
