#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
int n,m;
int sum;
struct edge{
    int from,to;
};
int friends[20];
struct edge e[100];
void dfs(int v)
{
    if(v==m+1){
        for(int i=1;i<=n;i++)
            if(friends[i])
                return ;
        sum++;
        return ;
    }
    int from=e[v].from;
    int to=e[v].to;
    if(friends[to]&&friends[from]){
        friends[to]--;friends[from]--;
        dfs(v+1);
        friends[to]++;friends[from]++;
    }
    dfs(v+1);

}

int main ()
{
    int T;
    scanf("%d",&T);
    while(T--){
        sum=0;
        memset(friends,0,sizeof(friends));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            e[i].from=a;e[i].to=b;
            friends[a]++;
            friends[b]++;
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(friends[i]%2){
                flag=1;break;
            }
        }
        if(flag){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            friends[i]=friends[i]/2;
        }
        dfs(1);
        printf("%d\n",sum);
    }
}
