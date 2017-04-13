#include "cstdio"
#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;
typedef long long LL;
int n;
const LL mod=1e9+7;
LL pow(int n)
{
    if(n==0)
        return 1;
    if(n==1){
        return 2;
    }
    int a=n/2;
    if(n%2)
        return (((2*pow(a))%mod)*pow(a))%mod;
    else
        return (pow(a)*pow(a))%mod;

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        printf("%I64d\n",pow(n-1)-1);
    }
}
