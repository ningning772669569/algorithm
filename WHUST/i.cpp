#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int N,M;
char m[24][24];
int sum;
int vis[24][24];
int diri[]={0,0,0,1,-1};
int dirj[]={0,1,-1,0,0};
int dfs3(int i,int j)
{
    if(m[i][j]=='N'){
        //vis[i][j]=1;
        //sum++;
        return 1;
    }
    return 0;
}
int dfs2(int i,int j)
{
    int re=0;
    if(m[i][j]!='I')
        return 0;
    if(j-1>0){
        if(dfs3(i,j-1)){

            re=2;
        }
    }
    if(i-1>0){
        if(dfs3(i-1,j)){

            re+=40;
            }
    }
    if(j+1<=M){
        if(dfs3(i,j+1)){
            //vis[i][j]=1;
            re+=100;
        }
    }
    if(i+1<=N){
        if(dfs3(i+1,j)){
            //vis[i][j]=1;
            re+=3000;
        }
    }
    return 0;
}

void dfs(int i,int j)
{
    if(i==N&&j==M){
        MAX=max(MAX,sum);
    }
    if(m[i][j]!='W'){
        if(j==M){
            dfs(i+1,1);
        }
        else{
            dfs(i,j+1);
        }
    }
    if(i-1>0){
        int d;
        if(d=dfs2(i-1,j)){
            while(d){
                int c=d%10;
                if(c){

                }
            }
        }
    }
    if(i+1<N){
        if(dfs2(i+1,j))
    }
    if(j-1>0){
        if()
    }
}
int main ()
{
    while(scanf("%d %d",&N,&M)==2){
        for(int i=1;i<=N;i++){
            getchar();
            for(int j=1;j<=M;j++){
                scanf("%c",&m[i][j]);
            }
        }
        dfs(1,1);

    }
}
