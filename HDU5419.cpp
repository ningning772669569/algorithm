#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=51000;
typedef long long LL;
struct node{
    LL l,r;
    LL num;
};
node seg[maxn<<3];
LL lazy[maxn<<3];
LL L[maxn];
LL R[maxn];
LL w[maxn];
LL N,M;
LL re;
LL gcd(LL a,LL b)
{
  return b == 0 ? a : gcd(b,a%b) ;
}
LL getnum(LL n)
{
    LL re=(n-2)*(n-1)*n/6;
    return re;
}
void build(LL l,LL r,LL rt)
{
    seg[rt].l=l;
    seg[rt].r=r;
    seg[rt].num=0;
    if(l==r)
        return;
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}
void pushdown(LL rt)
{
    if(lazy[rt]){
        lazy[rt*2]+=lazy[rt];
        lazy[rt*2+1]+=lazy[rt];
        lazy[rt]=0;
    }
}
void update(LL l,LL r,LL rt,LL c)
{

    //if(seg[rt].l > r || l > seg[rt].r)
        //return ;
    if(l<=seg[rt].l && r>=seg[rt].r){

        seg[rt].num+=c;
        lazy[rt]+=c;
        //cout<<" "<<l<<" "<<r<<" "<<seg[rt].num<<endl;
        return ;
    }
    pushdown(rt);
    int mid=(seg[rt].l+seg[rt].r)/2;
    if(l<=mid)
        update(l,r,rt*2,c);
    if(mid<r)
        update(l,r,rt*2+1,c);

}
void query(LL rt)
{

    if(seg[rt].r==seg[rt].l){
        seg[rt].num=lazy[rt];
        if(seg[rt].num<3)
            return ;
        LL tep=getnum(seg[rt].num);
        //cout<<seg[rt].l<<"   "<<tep*w[seg[rt].l]<<endl;
        re+=tep*w[seg[rt].l];
        return;
    }
    pushdown(rt);
    query(rt*2);query(rt*2+1);


}
void init()
{
    memset(lazy,0,sizeof(lazy));
    build(1,N,1);
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%I64d%I64d",&N,&M);

        init();

        for(LL i=1;i<=N;i++) scanf("%I64d",&w[i]);
        for(LL i=1;i<=M;i++) scanf("%I64d%I64d",&L[i],&R[i]);
        for(LL i=1;i<=M;i++) update(L[i],R[i],1,1);
        re=0;
        query(1);
        LL a=re;
        if(a==0){
            printf("0\n");
            continue;
        }
        if(M<3){
            printf("0\n");
            continue;
        }
        //cout<<"****"<<a<<"*******"<<endl;
        LL b=getnum(M);
        LL c=gcd(a,b);
        a/=c;b/=c;
        //cout<<"****"<<a<<"*******"<<endl;
        if(b==1){
            printf("%I64d\n",a/b);
        }
        else
            printf("%I64d/%I64d\n",a,b);
    }
    return 0;
}
