#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef unsigned long long LL;
LL N,M;
LL gcd(LL a,LL b)
{
    return b==0? a:gcd(b,a%b);
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%I64d%I64d",&N,&M);
        if(N>M){
            printf("-1\n");continue;
        }
        if(M%N){
            printf("-1\n");continue;
        }
        LL step=0;
        int flag=1;
        while(N!=M){
            LL k=gcd(M/N,N);
            if(k==1){
                flag=0;
                break;
            }
            N*=k;
            step++;
        }
        if(flag)
            printf("%d\n",step);
        else
            printf("-1\n");

    }
    return 0;

}
