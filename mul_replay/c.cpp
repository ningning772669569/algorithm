#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn=1e5+1000;
int n;
LL sum[maxn];
LL num[maxn];
int main ()
{
    memset(num,0,sizeof(num));

    for(int i=2;i<maxn;i++){
        if(!num[i]){

            num[i]=1;
        }
        for(int j=2*i;j<maxn;j+=i){
                if(num[j]<i){

                    num[j]=i;
                }
        }

    }

    for(int i=1;i<=1000;i++){
        printf("%I64d\n",num[i]);
    }
    for(int i=1;i<maxn;i++){
        sum[i]=sum[i-1]+num[i];
    }

    while(scanf("%d",&n)!=EOF){

        printf("%I64d\n",sum[n]);

    }
    return 0;
}
