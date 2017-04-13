#include "cstdio"
#include "algorithm"
#include "iostream"
#include "vector"
#include "cstring"
#define MAX 1000
using namespace std;
struct Node{
    int l,r;
    int num;
};
int N,D;
int dp[MAX];
void build (struct Node Seg[],int i,int l,int r);
void update (struct Node  Seg[],int i,int l,int r,int num);
struct Node * init (int num[]);
int query (struct Node Seg[],int i,int l,int r);
int main ()
{
    cin >>N >>D;
    int dp[N+1];
    int lazy[N+1];
    memset(dp,0,sizeof(dp));
    memset(lazy,0,sizeof(lazy));
    int num[N+1];
    for(int i=1;i<=N;i++){
        scanf("%d",&num[i]);
    }
    struct  Node * Seg;
    Seg=init(num);
    dp[1]=0;
    update(Seg,1,num[1],num[1],1);
    for(int i=2;i<=N;i++){
        dp[i]=query(Seg,1,num[i]-D,num[i]+D);
        //printf("%d %d \n",i,dp[i]);
        update(Seg,1,num[i],num[i],dp[i]);
    }
    int sum=0;
    for(int i=1;i<=N;i++){
        sum+=dp[i];

    }
    cout <<sum <<endl ;
    return 0;
}
struct Node * init (int num[])
{
    struct Node * Seg;
    int _max=num[1],_min=num[1];
    for(int i=1;i<=N;i++){
        if(num[i]<_min){
            _min=num[i];
        }
        if(num[i]>_max){
            _max=num[i];
        }
    }
    Seg=new struct Node [N*4+5];
    build (Seg,1,_min-D,_max+D);
    return Seg;
}
void build (struct Node Seg[],int i,int l,int r)
{
    Seg[i].l=l;
    Seg[i].r=r;
    Seg[i].num=0;
    if(l==r){

    }else {
        int mid=(l+r)>>1;
        build(Seg,2*i,l,mid);
        build(Seg,2*i+1,mid+1,r);
    }

}

void update (struct Node  Seg[],int i,int l,int r,int num)
{
    if(Seg[i].l==Seg[i].r){
        Seg[i].num+=num;
    }else{
        int mid=(Seg[i].l+Seg[i].r)/2;
        if(l>mid)
            update(Seg,2*i+1,l,r,num);
        else if(r<=mid)
            update(Seg,2*i,l,r,num);
        else{
            update(Seg,2*i,l,mid,num);
            update(Seg,2*i+1,mid+1,r,num);
        }
    }
}
int query (struct Node Seg[],int i,int l,int r)
{
    if(Seg[i].l==l&&Seg[i].r==r){
        return Seg[i].num%9901;
    }
    int mid=(Seg[i].l+Seg[i].r)/2;
    if(l>mid){
           return  query(Seg,2*i+1,l,r);
    }
    else if(r<=mid){
           return  query(Seg,2*i,l,r);

    }
    else{
           return query(Seg,2*i,l,mid)+query(Seg,2*i+1,mid+1,r);
    }
}
