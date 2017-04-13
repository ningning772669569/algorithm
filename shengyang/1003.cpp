#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
using namespace std;
const int maxn=20010;

int n,m;
int dfsid;
int top[maxn];
int id[maxn];
int siz[maxn];
int dep[maxn];
int fa[maxn];
int son[maxn];
int add[250000];

vector<int> G[maxn];
struct node{
    int l,r,num;
};
node seg[maxn<<2];
int lazy[maxn<<2];
/*
void build(int l,int r,int rt)
{
    seg[rt].l=l;
    seg[rt].r=r;
    seg[rt].num=0;
    if(l==r){
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);

}
void update(int L,int R,int rt,int val)
{
    //cout<<1<<endl;
    if(L==seg[rt].l  && R==seg[rt].r){
        seg[rt].num+=val;
        return ;
    }
    //cout<<2<<endl;
    int mid=(seg[rt].l+seg[rt].r)/2;
    if(R<=mid){
        //cout<<3<<endl;
        update(L,R,rt*2,val);
    }
    else if(L>mid){
        //cout<<4<<endl;
        update(L,R,rt*2+1,val);
    }
    else{
        //cout<<5<<endl;
        update(L,mid,rt*2,val);
        update(mid+1,R,2*rt+1,val);
    }

}
void pushdown(int rt)
{
    if(seg[rt].num>0){
        seg[rt*2].num+=seg[rt].num;
        seg[rt*2+1].num+=seg[rt].num;
    }
    seg[rt].num=0;
}

int query(int rt)
{
    if(seg[rt].l==seg[rt].r){
        return seg[rt].num;
    }
    pushdown(rt);
    return max(query(rt*2),query(rt*2+1));

}
*/
void dfs1(int u,int f,int d)
{
    siz[u]=1;
    dep[u]=d;
    fa[u]=f;
    son[u]=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==f)    continue;
        dfs1(v,u,d+1);
        siz[u]+=siz[v];
        if(son[u]==0){
            son[u]=v;
        }
        else{
            if(siz[v]>siz[son[u]])
                son[u]=v;
        }
    }

}
void dfs2(int u,int t)
{
    top[u]=t;
    id[u]=++dfsid;
    if(son[u]){
        dfs2(son[u],t);
        for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa[u] || v==son[u])
            continue;
        dfs2(v,v);
        }
    }
}
void change(int u,int v)
{
    int f1=top[u],f2=top[v];
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        //update(id[f1],id[u],1,1);
        add[id[f1]]+=1;
        add[id[u]+1]-=1;

        u=fa[f1];
        f1=top[u];
    }
    if(u==v)
        return ;
        if(dep[u]>dep[v])
            swap(u,v);
        //update(id[son[u]],id[v],1,1);
        add[id[son[u]]]+=1;
        add[id[v]+1]-=1;



}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        dfsid=0;
        memset(son,0,sizeof(son));
        memset(lazy,0,sizeof(lazy));
        for(int i=1;i<n;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            G[l].push_back(r);
            G[r].push_back(l);
        }
        dfs1(1,0,1);
        dfs2(1,1);
        //build(1,n,1);
        //cout<<2222<<endl;
        memset(add,0,sizeof(add));

        for(int i=1;i<=m-n+1;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            //cout<<3333<<endl;
            change(from,to);
            //cout<<4444<<endl;
        }
        int re=m;
        //re=query(1);
        for(int i=1;i<=n;i++){
            //printf("%d\n",add[i]);
            add[i]+=add[i-1];
            if(i>=2){
                re=min(re,add[i]);
            }
        }
        printf("Case #%d: %d\n",t,re+1);
    }
    return 0;
}
