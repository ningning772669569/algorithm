#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "map"
#include "vector"
#include "queue"
#include "math.h"
using namespace std;
const int maxn=100010;
struct node {
    int l,r,num;
};
map<int,int> mm;
int num[maxn];
int tnum[maxn];
int dp1[maxn];
int dp2[maxn];
int N,L;
node seg[maxn<<2];
void build(int l,int r,int rt)
{
    seg[rt].r=r;
    seg[rt].l=l;
    seg[rt].num=0;
    if(l==r)
        return ;
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);

}
int bsearch(int a[],int n,int c)
{
    int l=1,r=n;
    int mid=(l+n)/2;
    while(l<=r){
        if(a[mid]<c&&a[mid+1]>=c)
            return mid+1;
        else if(a[mid]>c)
            r=mid-1;
        else
            l=mid+1;
    }
}
void pushup(int rt)
{
    rt/=2;
    while(rt>=1){
        seg[rt].num=max(seg[rt*2].num,seg[rt*2+1].num);
        rt/=2;
    }

}
void update(int rt,int pos,int c)
{
    if(seg[rt].l==seg[rt].r){
        seg[rt].num=max(seg[rt].num,c);
        pushup(rt);
        return;
    }
    int mid=(seg[rt].l+seg[rt].r)/2;
    if(pos<=mid){
        update(rt*2,pos,c);
    }
    else
        update(rt*2+1,pos,c);
}
int query(int L,int  R,int rt)
{
    if(L<=seg[rt].l && R>=seg[rt].r){
        return seg[rt].num;
    }
    int mid=(seg[rt].l+seg[rt].r)/2;
    if(R<=mid)
        return query(L,R,rt*2);
    else if(L>mid)
        return query(mid+1,R,rt*2);
    else{
        return max(query(L,mid,rt*2),query(mid+1,R,rt*2+1));

    }

}
void LIS(int a[],int n,int dp[])
{

    int *c=new int [n+10];
    c[1]=a[1];dp[1]=1;
    int size=1;
    for(int i=2;i<=n;i++){
        int j;
        if(a[i]<=c[1])  j=1;
        else if(a[i]>c[size])
            j=++size;
        else
            j=bsearch(c,size,a[i]);

        c[j]=a[i]; dp[i]=j;
    }
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        mm.clear();
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        scanf("%d %d",&N,&L);
        //cout << N <<" "<<L<<endl;
        for(int i=1;i<=N;i++){
            scanf("%d",&num[i]); tnum[i]=num[i];
        }
        sort(tnum+1,tnum+1+N);
        int size=unique(tnum+1,tnum+1+N)-tnum;
        //cout<<size<<endl;
        for(int i=1;i<size;i++) mm[tnum[i]]=i;
        for(int i=1;i<=N;i++) num[i]=mm[num[i]];
        LIS(num,N,dp1);
        //cout<<"******"<<endl;
        for(int i=N;i>=1;i--)   tnum[N-i+1]=0-num[i];
        LIS(tnum,N,dp2);
        //cout<<"******"<<endl;
        for(int i=1;i<=N/2;i++) swap(dp2[i],dp2[N-i+1]);
        int re=0;
        build(1,size-1,1);
        for(int i=1;i+L-1<=N;i++){
            //cout<<"***"<<i<<"***"<<endl;
            int bac=0,len=0;
            if(i>1)
                update(1,num[i-1],dp1[i-1]);

            if(i+L<=N){
                //cout<<"******"<<endl;
                len=dp2[i+L];
                bac=query(1,num[i+L],1);
                //cout<<"******"<<endl;
            }
            else{
                bac=seg[1].num;
            }
            re=max(re,bac+len);
        }
        printf("Case #%d: %d\n",t,re);
    }
    return 0;
}
