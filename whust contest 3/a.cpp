#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;

typedef unsigned long long LL;
const int maxn=100009;
const int zhuanhuan=1000000;
struct Time{
    int h,m,s;
};
int n;
struct Time time[maxn];
bool cmp(const struct Time &p,const struct Time & q)
{
    if(p.h!=q.h){
        return p.h<q.h;
    }
    else{
        if(p.m!=q.m){
            return p.m<q.m;
        }
        else{
            return p.s<q.s;
        }
    }
}
LL t[maxn];
LL sum[maxn];
int main ()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&time[i].h,&time[i].m,&time[i].s);
        }
        sort(time+1,time+1+n,cmp);
        for(int i=1;i<=n;i++){
            t[i]=time[i].h*zhuanhuan*zhuanhuan+time[i].m*zhuanhuan+time[i].s;
            sum[i]=sum[i-1]+t[i];
        }
        LL ans; memset(&ans,0x3f,sizeof(ans));
        for(int i=1;i<=n;i++){
            LL tep=(i-1)*t[i]-sum[i-1];
            LL tep2=(i-1)*12*zhuanhuan*zhuanhuan;
            LL tep3=tep2-tep;
            LL tep4=sum[n]-sum[i]-(n-i)*t[i];
            ans=min(ans,tep3+tep4);
        }
        LL hour=ans/zhuanhuan/zhuanhuan;
        LL min=ans/zhuanhuan;
        min%=zhuanhuan;
        LL sec=ans%zhuanhuan;
        cout << hour<<" "<<min<<" "<<sec<<std::endl;
    }
}
