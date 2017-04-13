#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n;
struct node{
    int num;
    int ok;
    node(int num,int ok):num(num),ok(ok){}
};
vector<struct node> g[100005];
vector<int> result;
bool vis[100005];
int f[100005];
bool have[100005];
int sum;
void init()
{
    sum=0;
    result.clear();
    memset(vis,0,sizeof(vis));
    memset(f,0,sizeof(f));
    memset(have,0,sizeof(have));
}
void push_up(int v)
{
    int fa=f[v];
    have[v]=false;
    while(fa){
        have[fa]=false;
        fa=f[fa];
    }
}
void dfs(int v,int fa)
{
    int sons=g[v].size();
    f[v]=fa;
    for(int i=0;i<sons;i++){
        if(g[v][i].num==fa){
            if(g[v][i].ok==2){
                have[v]=true;
            }
            break;
        }
    }
    if(sons>1){
        for(int i=0;i<sons;i++){
            int tepnum=g[v][i].num;
            if(tepnum!=fa)
                dfs(tepnum,v);
        }
        if(have[v]){
            sum++;
            push_up(v);
            result.push_back(v);
        }
    }
    else{
        if(have[v]){
            push_up(v);
            sum++;
            result.push_back(v);
        }
    }
}
int main ()
{
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<n;i++){
            int a,b,ok;
            scanf("%d %d %d",&a,&b,&ok);
            struct node tep(b,ok);
            g[a].push_back(tep);
            tep.num=a;
            g[b].push_back(tep);
        }
        dfs(1,0);
        printf("%d\n",sum);
        for(vector<int>::size_type i=0;i<result.size();i++){
            printf("%d",result[i]);
            if(i<result.size()-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;

}
