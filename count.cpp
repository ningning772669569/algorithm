#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
int n,limit;
int dp[100011],num[100011],hash0[100011];
struct B
{
    int n,index;
}C[100011];
struct Seg
{
    int l,r,mid;
    int num;
}T[400011];
void build(int l,int r,int k)
{
    T[k].l=l;
    T[k].r=r;
    T[k].num=0;
    T[k].mid=(l+r)>>1;
    if(l==r)    return ;
    build(l,T[k].mid,2*k);
    build(T[k].mid+1,r,2*k+1);
}
void update(int l,int r,int dir,int k)
{
    if(T[k].l==l && T[k].r==r)  {T[k].num+=dir;T[k].num%=9901;return ;}
    if(r<=T[k].mid)      update(l,r,dir,2*k);
    else if(l>T[k].mid)  update(l,r,dir,2*k+1);
    else
    {
        update(l,T[k].mid,dir,2*k);
        update(T[k].mid+1,r,dir,2*k+1);
    }
}
int find(int aim,int k)
{
    int ans=0;
    if(T[k].l==T[k].r && T[k].l==aim)   return T[k].num%9901;
    if(T[k].l<=aim && aim<=T[k].r)
    {
        ans+=T[k].num;
        if(aim<=T[k].mid)    ans+=find(aim,2*k);
        else                ans+=find(aim,2*k+1);
    }
    return ans%9901;
}
int cmp(const void *a,const void *b)
{
    struct B *c,*d;
    c=(struct B *)a;
    d=(struct B *)b;
    return c->n-d->n;
}
int main()
{
    int ans;
    int i;
    int l,r;
    int low,up,mid;
    while(scanf("%d%d",&n,&limit)!=-1)
    {
        build(1,n,1);
        for(i=1;i<=n;i++)    {scanf("%d",&num[i]);C[i].n=num[i];C[i].index=i;}
        C[0].n=-111111111;
        qsort(C,n+1,sizeof(C[0]),cmp);
        for(i=1;i<=n;i++)    hash0[C[i].index]=i;

        memset(dp,0,sizeof(dp));
        ans=0;
        for(i=1;i<=n;i++)
        {
            dp[i]=find(hash0[i],1);
            ans+=dp[i];
            ans%=9901;
            low=1;up=hash0[i];mid=(low+up)>>1;
            while(low<=up)
            {
                if(C[mid].n-num[i]<-limit)   low=mid+1;
                else                        up=mid-1;
                mid=(low+up)>>1;
            }
            l=low;
            low=hash0[i];up=n;mid=(low+up)>>1;
            while(low<=up)
            {
                if(C[mid].n-num[i]<=limit)   low=mid+1;
                else                        up=mid-1;
                mid=(low+up)>>1;
            }
            r=low-1;
            update(l,r,(dp[i]+1)%9901,1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
