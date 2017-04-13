#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
LL N;
void gcd(LL a,LL b,LL &d ,LL &x,LL&y)
{
    if(!b){
        d=a;x=1;y=0;
    }
    else{
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
LL inv(LL a,LL n)
{
    LL d,x,y;
    gcd(a,n,d,x,y);
    return d==1 ?(x+n)%n:-1;
}
int main ()
{
    LL three=inv(3,MOD);
    LL two=inv(2,MOD);
    LL six=inv(6,MOD);
    LL tw=inv(12,MOD);
    int T;
    scanf("%d",&T);
    for(int caseid=1;caseid<=T;caseid++){
        scanf("%lld",&N);

        LL t1=(N+1)%MOD;
        LL t2=(N)%MOD;
        LL t=(t1*t2)%MOD; ///n(n+1)

        LL p1=(t*t)%MOD;
        p1=(p1*7)%MOD;
        p1=(p1*tw)%MOD;

        LL p2=(2*N+1)%MOD;
        p2=(p2*t)%MOD;
        p2=(p2*3)%MOD;
        p2=(p2*tw)%MOD;

        LL p3=(t*tw)%MOD;

        LL p4=(t2*t2)%MOD;
        p4=(p4*t)%MOD;
        p4=(p4*two)%MOD;

        LL re1=(p1+p2)%MOD;
        LL re2=(p3+p4)%MOD;
        LL re=(re1+re2)%MOD;
        cout<<re<<endl;
    }
}
