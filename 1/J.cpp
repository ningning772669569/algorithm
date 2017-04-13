#include "algorithm"
#include "cstring"
#include "cstdio"
#include "iostream"
#define  MAX 10010
using namespace std;
int fa[MAX];
int dep[MAX];
int anc[MAX][30];
int N;
void RMQ()
{
    memset(anc,0,sizeof(anc));
    for(int i=1;i<=N;i++){
        anc[i][0]=fa[i];

    }
    for(int k=1;k<20;k++){
        for(int j=1;j<=N;j++){
            anc[j][k]=anc[anc[j][k-1]][k-1];
        }
    }
}
int swim (int u,int H)
{
    int k=0;
    while(H){
        if(H&1){
            u=anc[u][k];

        }
        k++;
        H=H/2;
    }
    return u;
}
int LCA(int a,int b)
{
    if(dep[a]>dep[b]) swap(a,b);
    b=swim(b,dep[b]-dep[a]);
    if(a==b)    return a;
    while(1){
        int k;
        for(k=0;anc[a][k]!=anc[b][k];k++);
        if(k==0)    return anc[a][0];
        a=anc[a][k-1];
        b=anc[b][k-1];
    }
}
void DFS()
{
    memset(dep,0,sizeof(dep));
    for(int i=1;i<=N;i++){
        int x=i;
        while (fa[x]){
            dep[i]++;
            x=fa[x];
        }
    }
}
int main ()
{
    int T;
    cin >> T;
    while (T--){
        memset(fa,0,sizeof(fa));
        int father,son;
        scanf("%d",&N);
        for(int i=1;i<N;i++){
            scanf("%d %d",&father,&son);
            fa[son]=father;
        }
        int _a,_b;
        scanf("%d %d",&_a,&_b);
        RMQ();
        DFS();
        printf("%d\n",LCA(_a,_b));

    }
}

