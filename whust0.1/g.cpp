#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=18;
int n,k;
int num[maxn];
int vis[maxn];
int sum;
void dfs(int v,int geshu)
{
    if(geshu==n){
        sum++;
        return ;
    }
    int low,high;
    if(v-k>1){
        low=v-k;
    }
    else{
        low=1;
    }
    if(v+k<=n){
        high=v+k;
    }
    else
        high=n;
    for(int i=low;i<=high;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,geshu+1);
            vis[i]=0;
        }
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&k);
        if(k<=1){
            printf("0\n");
            continue;
        }
        sum=0;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,1);
        }
        printf("%d\n",sum);
    }
}
