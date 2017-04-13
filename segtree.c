/*************************************************************************
	> File Name: a.cpp
	> Author:Just a Hook 
	> Mail: 
	> Created Time: 2015年12月03日 星期四 19时22分58秒
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;

int N,Q;
struct node{
    int l,r,val,sum;
};
node seg[maxn<<2];
int lazy[maxn<<2];
void pushdown(int rt)
{
    if(lazy[rt]){
        lazy[rt*2]=lazy[rt];
        lazy[rt*2+1]=lazy[rt];
        seg[rt*2].val=lazy[rt]*(seg[rt*2].r-seg[rt*2].l+1);
        seg[rt*2+1].val=lazy[rt]*(seg[rt*2+1].r-seg[rt*2+1].l+1);
        lazy[rt]=0;
    }
}
void build(int rt,int l,int r)
{
    seg[rt].l=l;
    seg[rt].r=r;
    if(l==r){
        seg[rt].val=1;
        return ;
    }    
    int mid=(l+r)/2;
    build(rt*2,l,mid);
    build(rt*2+1,mid+1,r);
    seg[rt].val=seg[rt*2].val+seg[rt*2+1].val;
}
void update(int rt,int l,int r,int z)
{
    if(l==seg[rt].l && r==seg[rt].r){
        seg[rt].val=(seg[rt].r-seg[rt].l+1)*z;
        lazy[rt]=z;
        return ;
    }
    pushdown(rt);
    int mid=(seg[rt].l+seg[rt].r)/2;
    if(l>mid){
        update(rt*2+1,l,r,z);
    }
    else if(r<=mid){
        update(rt*2,l,r,z);
    }
    else{
        update(rt*2,l,mid,z);
        update(rt*2+1,mid+1,r,z);
    }
    seg[rt].val=seg[rt*2].val+seg[rt*2+1].val;

}
LL query(int i, int l, int r, int ql, int qr) {  
    if(l > qr || ql > r)  
        return 0;  
    if(l >= ql && r <= qr)  
        return sum[i];  
    pushDown(i, l, r);  
    int mid = l + r >> 1;  
    return query(i << 1, l, mid, ql, qr)   
        + query(i << 1 | 1, mid + 1, r, ql, qr);  
}  
int main()
{
    int T;
    scanf("%d",&T);
    for(int caseid=1;caseid<=T;caseid++){
        cin>> N>>Q;
        memset(lazy,0,sizeof(lazy));
        build(1,1,N);
        for(int i=1;i<=Q;i++){
            int l,r,z;
            //cin>>l>>r>>z;
            scanf("%d%d%d",&l,&r,&z);
            update(1,l,r,z);
        }
        
        printf("Case %d: The total value of the hook is %d.\n",caseid,seg[1].val);
    }
    return 0;
}
