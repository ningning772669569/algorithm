#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct node{
    int num,ok;
};
bool vis[100005];
int sum;
int n;
vector<struct node> g[100005];
vector<int> result;
int dfs(int v,int flag)
{
    int sons=g[v].size();

    vis[v]=1;
    int s=0;
    for(int i=0;i<sons;i++){
        int sonnum=g[v][i].num;
        if(!vis[sonnum]){
            if(g[v][i].ok==2){
                s+=dfs(sonnum,1);
            }
            else{
                s+=dfs(sonnum,0);
            }
        }
    }
    if(flag&&!s)
    {
        result.push_back(v);
        sum++;
        return 1;

    }
    return s;
}
int main ()
{
    while (scanf("%d",&n)!=EOF){
        sum=0;
        result.clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            struct node tep;
            tep.ok=c;
            tep.num=a;
            g[b].push_back(tep);
            tep.num=b;
            g[a].push_back(tep);
        }
        dfs(1,0);
        printf("%d\n",sum);
        for(vector<int>::size_type i=0;i<result.size();i++){
            printf("%d",result[i]);
            if(i<result.size()-1)
                printf(" ");
        }
        printf("\n");
    }
}
