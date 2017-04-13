#include "cstdio"
#include "iostream"
#include "cstring"
#include "algorithm"
#include "set"
#include "map"
#include "vector"
using namespace std;
const int maxn=1e5+10;
struct Node{
    int l,r,num;
};
int l[maxn];
int r[maxn];
int vis[maxn];
int w[maxn];
int treeline[maxn];
map<int,int> m;
vector <int> tree[maxn];
struct Node seg[maxn<<2];
int lazy[maxn<<2];
int dfsid;
int n,k;
void dfs(int v)
{
    vis[v]=1;
    dfsid++;
    l[v]=dfsid;
    treeline[dfsid]=w[v];
    int sons=tree[v].size();
    for(int i=0;i<sons;i++){
        int son=tree[v][i];
        if(!vis[son])
            dfs(son);
    }
    r[v]=dfsid;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&k);
        int id=0;
        m.clear();
        for(int i=1;i<n;i++){

            int num;
            scanf("%d",&num);
            if(m[num]==0){
                id++;
                m[num]=id;
            }
            w[i]=m[num];

        }
        for(int i=1;i<n;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        dfsid=0;
        dfs(1);
    }
}
