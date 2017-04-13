#include <bits/stdc++.h>
using namespace std;
const int maxn=100009;
const int MAXN=10000007;
typedef long long LL;
int N,Q;
int num[maxn];
int prime[10000009];
struct node{
    int l,r;
    int flag;
    int lazy;
    int val;
}
node seg[maxn<<2];
void get_prime()
{
    prime[0]=1;
    for(int i=2;i<=MAXN;i++){
        if(!prime[i]){
            for(int j=2*i;j<MAXN;j+=i){
                prime[j]=1;
            }
        }
    }
}
void pushdown(int rt)
{
    if(seg[rt].flag){
        seg[rt]
    }

}
void build(int rt,int l,int r)
{
    seg[rt].l=l;
    seg[rt].r=r;
    if(l==r){
        seg[rt].lazy=0;
        seg[rt].flag=1;
        seg[rt].val=num[l];
        return ;
    }
    seg[rt].flag=0;
    seg[rt].lazy=0;
    seg[rt].val=0;
    int mid=(l+r)/2;
    build(rt*2,l,mid);
    build(rt*2+1,mid+1,r);
}

void add(int rt,int l,int r,int v)
{
    if(l<=seg[rt].l && r>=seg[rt].r){
        seg[rt].lazy=v;
        seg[rt].val+=v;
        return ;
    }
    pushdown(rt);
    int mid=(seg[rt].l+seg[rt].r)>>1;
    if(l>=mid+1){
        add(rt*2+1,l,r,v)
    }
    else if(seg[rt].r<=mid){
        add(rt*2,l,r,v);
    }
    else{
        add(rt*2,l,mid,v);
        add(rt*2+1,mid+1,r,v);
    }
}
void rep(int rt,int l,int r,int v)
{
    if(l<=seg[rt].l && r>=seg[rt].r){
        seg[rt].flag=1;
        seg[rt].val=v;
        return ;
    }
    pushdown(rt);
    int mid=(seg[rt].l+seg[rt].r)>>1;
    if(l>=mid+1){
        rep(rt*2+1,l,r,v);
    }
    else if(r<=mid){
        rep(rt*2,l,r,v);
    }
    else{
        rep(rt*2,l,mid,v);
        rep(rt*2+1,mid+1,r,v);
    }


}
void query(int rt,int l,int r)
{
    if(l<=seg[rt].l && r>=seg[rt].r &&seg[rt].flag){
        if(!prime[seg[rt].val){
            result+=seg[rt].r-seg[rt].l+1;
        }
    }
    pushdown(rt);
}
int main ()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&Q);
        for(int i=1;i<=N;i++){
            scanf("%d",&num[i]);
        }
        for(int i=1;i<=Q;i++){
            getchar();
            char choice;
            scanf("%c",&choice);
        }
    }
}
