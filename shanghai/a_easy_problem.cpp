#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=100010;
LL seg[maxn<<2];
LL num[maxn];
LL Q,M;

LL query(LL l,LL r,LL L,LL R,LL rt)
{
    if(l==r){
       // cout<<"  ^^^^ "<<l<<"  ^^^^^  "<<r<<"  ^^^^^^  "<<(seg[rt]==0? 1:seg[rt])<<endl;
        return seg[rt]==0? 1:seg[rt];

    }
    LL tepl,tepr;
    LL mid=(l+r)/2;
    if(R<=mid){
        return (query(l,mid,L,R,rt*2))%M;
    }
    else if(L>mid){
        return (query(mid+1,r,L,R,rt*2+1))%M;
    }
    else{
        tepl=query(l,mid,L,mid,rt*2);
        tepr=query(mid+1,r,mid+1,R,rt*2+1);
        return (tepl*tepr)%M;
    }
}
void update(LL l,LL r,LL rt,LL pos,LL tnum)
{
    if(l==r){
        seg[rt]=tnum;
        return;
    }
    LL mid=(l+r)/2;
    if(pos<=mid)
        update(l,mid,rt*2,pos,tnum);
    else{
        update(mid+1,r,rt*2+1,pos,tnum);
    }

}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int caseid=1;caseid<=T;caseid++){
        memset(seg,0,sizeof(seg));
        scanf("%I64d %I64d",&Q,&M);
        for(LL i=1;i<=Q;i++){
            LL choice,tnum;
            scanf("%I64d %I64d",&choice,&tnum);
            if(choice==1){
                update(1,Q,1,i,tnum);
                printf("%I64d\n",query(1,Q,1,i,1)%M);
            }
            else{
                update(1,Q,1,tnum,0);
                printf("%I64d\n",query(1,Q,1,i,1)%M);
            }
        }
    }
}

