#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=100010;

int Q;
LL M;
LL seg[maxn<<2];

void build(int l,int r,int rt)
{
    if(l==r){
        seg[rt]=1;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    seg[rt]=1;
}
void pushup(LL rt)
{
    rt/=2;
    while(rt>=1){
        seg[rt]=(seg[rt*2]*seg[rt*2+1])%M;
        rt/=2;
    }
}
void update(LL l,LL r,LL rt,LL pos,LL num)
{
    if(l==r){
        seg[rt]=num;
        pushup(rt);
        return;
    }

    LL mid=(l+r)/2;
    if(pos<=mid){
        update(l,mid,rt*2,pos,num);
    }
    else{
        update(mid+1,r,rt*2+1,pos,num);
    }

}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        printf("Case #%d:\n",t);
        scanf("%I64d %I64d",&Q,&M);
        build(1,Q,1);
        for(LL i=1;i<=Q;i++){
            int choice;LL tnum;
            scanf("%d %I64d",&choice,&tnum);
            if(choice==1){
                update(1,Q,1,i,tnum);
                printf("%I64d\n",seg[1]);
            }
            else{
                update(1,Q,1,tnum,1);
                printf("%I64d\n",seg[1]);
            }
        }
    }
}
