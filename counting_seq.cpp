#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "map"
#include "vector"
#include "queue"
#include "utility"
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=100010;
const int mod =9901;

int n,d;
int _end;
LL num[maxn];
LL s[maxn];
LL seg[maxn<<2];


void pushdown(int  rt)
{
    if(seg[rt])
    {
        seg[2*rt]=(seg[2*rt]+seg[rt])%mod;
        seg[2*rt+1]=(seg[2*rt+1]+seg[rt])%mod;
        seg[rt]=0;
    }
    //seg[rt]=0;
}

int query(int l,int r,int rt,int mm)
{
    if(l==r)
        return seg[rt];
    else {
        pushdown(rt);
        int m=(l+r)>>1;
        if(mm<=m)
            return query(l,m,rt*2,mm);
        else
            return query(m+1,r,rt*2+1,mm);
    }

}


void update(int l,int r,int rt,int L,int R,int c)
{
    if(L<=l&&r<=R){
        seg[rt]=(seg[rt]+c)%mod;
        return ;
    }
    else {
        pushdown(rt);
        int m=(l+r)>>1;
        if(L<=m)
        update(l,m,rt*2,L,R,c);
        if(R>m)
        update(m+1,r,rt*2+1,L,R,c);;

    }
}
pii range(LL a)
{
    LL * f=lower_bound(s+1,s+_end,a-d);
    LL * b=lower_bound(s+1,s+_end,a+d);
    if((b==s+_end)||(*b)>a+d)
        return make_pair(f-s,b-1-s);
    else
        return make_pair(f-s,b-s);

}
int Find(LL a)
{
    LL * t=lower_bound(s+1,s+_end,a);
    return t-s;
}
int main ()
{
    while(scanf("%d %d",&n,&d)==2){

        for(int i=1;i<=n;i++){
            scanf("%I64d",&num[i]);
            s[i]=num[i];
        }
        sort(s+1,s+1+n);
        _end=unique(s+1,s+1+n)-s;
        memset(seg,0,sizeof(seg));
        int sum=0;
        pii tt=range(num[1]);
        update(1,_end-1,1,tt.first,tt.second,1);
        for(int i=2;i<=n;i++){
            int pos=Find(num[i]);
            int tep=query(1,_end-1,1,pos);
            tt=range(num[i]);
            sum+=tep;
            sum%=mod;
            update(1,_end-1,1,tt.first,tt.second,tep+1);
        }
        printf("%d\n",sum);
    }
    return 0;
}
