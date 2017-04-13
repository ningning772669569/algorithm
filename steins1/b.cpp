#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int mod=1e9+7;
LL n;
LL gcd(LL a,LL b)
{
    return b==0? a:gcd(b,a%b);
}

void ggcd(LL a,LL b,LL & d,LL &x,LL &y)
{
    if(!b){
        d=a;x=1;y=0;
    }
    else{
        ggcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

LL inv(LL a,LL n)
{
    LL d,x,y;
    ggcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%I64d",&n);
        if(n==1)
        {
            printf("1\n");
            continue;

        }
        LL tep=1;
        for(LL i=1;i<=n/2;i++){

            tep=(tep*(n-i+1))%mod;
            LL invi=inv(i,mod);
            tep=(tep*invi)%mod;//cout<<"^^^^"<<tep<<endl;
        }


            LL a=n/2;
            LL b=n+1-a;
            LL c=gcd(a,b);
            a/=c;
            b/=c;
            //cout<<a<<"%%%"<<b;
            tep=(tep*a)%mod;
            printf("%I64d\n",tep);

    }
    return 0;
}
