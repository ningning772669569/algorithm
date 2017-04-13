#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#define MAX 1000005
#define MOD 1000000007
using namespace std;
typedef  long long  LL;
LL c[MAX];
void gcd(LL a,LL b,LL& d,LL &x,LL &y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
LL inv (LL a,LL n)
{
    LL d,x,y;
    gcd(a,n,d,x,y);
    return d==1? (x+n)%n : -1;
}
void init(int n)
{
    c[n]=c[0]=1;
    for(LL i=1;i<n;i++){
        c[i]=(c[i-1]*(n-i+1)%MOD)*(inv(i,MOD)%MOD)%MOD;
    }
}
int main ()
{
    int a,b,n;
    while(cin >>a >>b >>n){
        memset(c,0,sizeof(c));
        long long numa;
        long long sum=0;
        init(n);
        for(numa=0;numa<=n;numa++){
            long long check;
            check=a*numa+b*(n-numa);
            bool flag=1;
            while(check){
                int gewei=check%10;
                if(gewei==a||gewei==b){
                    check=check/10;
                    continue;
                }
                flag=0;
                break;
            }
            if(flag){
                sum=(sum+c[numa])%MOD;
            }
        }
        printf("%I64d\n",sum);
        }
        return 0;

}
