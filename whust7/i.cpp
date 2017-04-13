#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
int N,M;
vector <int> rela[151];
int pos[152];
int vis[151];
int dfs(int v,int n)
{
    if(!vis[v]){
        vis[v]=1;
        if(n==N){
            vector<int>::size_type sons;
            for(sons=0;sons<rela[v].size();sons++){
                if(rela[v][sons]==1){
                    pos[n]=v;
                    return 1;
                }

            }
            vis[v]=0;
            return 0;
        }
        vector<int>::size_type num=rela[v].size();
        int flag=0;
        for(num=0;num<rela[v].size();num++){
            if(vis[rela[v][num]])
                continue;
            if(dfs(rela[v][num],n+1)){
                flag=1;
                pos[n]=v;
                break;
            }
        }
        vis[v]=0;
        if(flag)
            return 1;
        return 0;
    }
}
int main ()
{
    while(scanf("%d %d",&N,&M)==2){
        memset(pos,0,sizeof(pos));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++)
            rela[i].clear();
        for(int i=1;i<=M;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            rela[from].push_back(to);
            rela[to].push_back(from);
        }
        if(dfs(1,1)){
            for(int i=1;i<=N;i++){
                printf("%d",pos[i]);
                if(i<N){
                    printf(" ");
                }
            }
            printf("\n");
        }
        else {
            printf("no solution\n");
        }
    }
}
