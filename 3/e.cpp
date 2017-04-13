#include  "algorithm"
#include "cstdio"
#include  "cstring"
#include "iostream"
#define MAX 1000005
#define MOD 1000000007
using namespace std;

long long c[MAX];
void init (int n)
{
    c[0]=c[n]=1;
    for(int i=1;i<n;i++){
        c[i]=c[i-1]*(n-i+1)/i%MOD;
    }
}
int main ()
{
    int a,b,n;
    cin >>a >>b >>n;

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
            }
            if(flag){
                sum=(sum+c[numa])%MOD;
            }
        }
        printf("%ld",sum);
        return 0;

}
