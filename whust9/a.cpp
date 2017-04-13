#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"
#include "set"
#include "map"
#define MAX 100001
using namespace std;

struct Query{
    int id;
    int l;
    int r;
};
int n,k;
int w[100001];
int l[MAX];
int r[MAX];
int a[MAX];
map<int,int> m;
vector<int> tree[100001];
vector<int> show[MAX];
int vis [100001];
struct Query query[MAX];
int dfsid=0;
int seg[MAX<<2];
void dfs (int v)
{
    l[v]=dfsid;
    vis[v]=1;
    a[dfsid]=w[v];
    int sons=tree[v].size();
    for(int i=0;i<sons;i++){
        if(!vis[tree[v][i]]){
            dfsid++;
            dfs(tree[v][i]);
        }
    }
    r[v]=dfsid;
}
bool cmp(const struct Query&p,const struct Query &q)
{
    return p.r<q.r;
}
void build(int l,int r,int v)
{
    seg[v]=0;
    if(l==r)
        return;
    int mid=(l+r)/2;
    build(l,mid,v*2);
    build(mid+1,r,v*2+1);
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&k);
        int id=0;
        for(int i=1;i<=n;i++){
            tree[i].clear();
            show[i].clear();
        }
        for(int i=1;i<=n;i++){

            scanf("%d",&w[i]);
            if(m[w[i]]==0){
                m[w[i]]=++id;
            }
            w[i]=m[w[i]];
        }
        for(int i=1;i<n;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        dfs(1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int num;
            scanf("%d",&num);
            query[i].id=num;
            query[i].l=l[num];
            query[i].r=r[num];
        }
        sort(query+1,query+1+q,cmp);
        build(1,n,1);
        for(int i=1;i<=n;i++){
            int num=a[i];
            show[num].push_back(i);
            int size=show[num].size();
            if(size>=k){

            }
        }
    }
}
