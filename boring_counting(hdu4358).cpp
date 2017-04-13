#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "queue"
using namespace std;
typedef long long LL;
const int maxn=101000;
struct Query{
    int l;
    int r;
    int v;
};


int N,K;
int Q;
int id;
int dfsid;
int val[maxn];
int l[maxn];
int r[maxn];
int a[maxn];
int seg[maxn<<2];
bool vis[maxn];
vector<int> tree[maxn];
vector<int> vv[maxn];
vector<struct Query> q;
map<int,int> m;
int ans[maxn];
void build()
{
    memset(seg,0,sizeof(seg));
}

void pushdown(int v)
{
    if(seg[v]){
        seg[v<<1]+=seg[v];
        seg[v<<1|1]+=seg[v];
        seg[v]=0;

    }
}

void update(int l,int r,int cur,int L,int R,int c)
{
    if(L<=l&&r<=R){
        seg[cur]+=c;
        return ;
    }
    pushdown(cur);
    int m=(l+r)>>1;
    if(L<m){
        update(L,m,cur*2,L,R,c);
    }
    if(R>m+1){
        update(m+1,cur*2+1,R,L,R,c);
    }


}

int query(int l, int r, int rt, int p)
{
    if (l == r) {
        return seg[rt];
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (p <= m) {
        return query(l, m, rt << 1, p);
    } else {
        return query(m + 1, r, rt << 1 | 1, p);
    }
}

int cmp(const struct Query & p,const struct Query & q)
{
    return p.r<q.r;
}

void dfs(int v)
{
    vis[v]=true;
    dfsid++;
    a[dfsid]=val[v];
    l[v]=dfsid;
    //vector<int>::size_type size=tree[v].size();
    for(vector<int>::size_type i=0;i<tree[v].size();i++){
        if(!vis[tree[v][i]]){
            dfs(tree[v][i]);
        }
    }
    r[v]=dfsid;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&N,&K);
        for(int i=1;i<=N;i++)
            tree[i].clear();
        for(int i=1;i<=N;i++){
            scanf("%d",&val[i]);
        }
        for(int i=1;i<=N-1;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            tree[from].push_back(to);
            tree[to].push_back(from);
        }

        m.clear();
        id=0;
        dfsid=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++){
            int num=val[i];
            if(m[num]==0){
                id++;
                m[num]=id;
                val[i]=m[num];
            }
            else{
                val[i]=m[num];
            }
        }
        dfs(1);
        q.clear();
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++){
            int num;
            scanf("%d",&num);
            q.push_back((Query){l[num],r[num],i});
        }
        sort(q.begin(),q.end(),cmp);
        vector<struct Query>::iterator iter=q.begin();
        for(int i=1;i<=N;i++){
            int num=a[i];
            vv[num].push_back(i);
            int size=vv[num].size();
            if(size>=K){
                if(size>K){
                    update(1,N,1,1,vv[num][size-K-1],-1);
                    update(1, N, 1, vv[num][size-K-1] + 1, vv[num][size-K], 1);
                }
                else{
                    update(1, N, 1, 1, vv[num][size-K], 1);
                }
            }
            while((*iter).r==i){
                ans[(*iter).v]=query(1,N,1,(*iter).l);
                iter++;
            }

        }

    }
    return 0;
}
