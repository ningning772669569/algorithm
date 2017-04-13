#include "cstdio"
#include "algorithm"
#include "string"
using namespace std;

const int MAX=10000;
int adj[8][8]={};
int main ()
{
    int sum;
    int next,lowest;
    int vis[8];
    int low[8];
    //memset(vis,0,sizeof(vis));
    //memset(low,MAX,sizeof(low));
    for(int m=0;m<8;m++){
        low[m]=MAX;
        vis[m]=0;
    }
    for(int i=0;i<8;i++)
        low[i]=adj[0][i];
    vis[0]=1;       //作为起点
    for(int i=1;i<8;i++){
        lowest=MAX;
        for(int j=1;j<8;j++){
            if(!vis[j]&&lowest>low[j]){
                next=j;
                lowest=low[j];

            }
        }
        sum+=lowest;
        for(int j=0;j<8;j++){
            if(low[j]>adj[next][j])
                low[j]=adj[next][j];
        }
    }
    printf("%d",sum);
}
