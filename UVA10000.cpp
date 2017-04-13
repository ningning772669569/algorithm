#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
int n,s;
int MAX;
int des;
vector<int> G[110];
int dis[110];
int main ()
{
    int caseid=0;
    while(scanf("%d",&n)!=EOF && n){

        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        scanf("%d",&s);
        int p,q;
        while(1){
            scanf("%d%d",&p,&q);
            if(!p)
            break;
            G[p].push_back(q);
        }

        memset(dis,0,sizeof(dis));
        dis[s]=1;
        for(int i=1;i<=n;i++){
            for(int u=1;u<=n;u++){
                if(dis[u])
                for(int k=0;k<G[u].size();k++){
                    int v=G[u][k];
                    dis[v]=max(dis[v],dis[u]+1);

                }
            }

        }
        MAX=0;
        des=0;
        for(int i=1;i<=n;i++){
            if(dis[i]>MAX)
                MAX=dis[i];
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==MAX){
                if(des==0 || des>i){
                    des=i;
                }
            }

        }
        ++caseid;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",caseid,s,MAX-1,des);
        printf("\n");
    }
    return 0;
}
