#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n,a,d;
int num[105];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(num,0,sizeof(num));
        int sum=0;
        scanf("%d %d %d",&n,&a,&d);
        num[1]=a;
        for(int i=2;i<=n;i++){
            num[i]=(i-1)*d+a;
        }
        for(int i=1;i<=n;i++)
            sum=sum+num[i];
        printf("%d\n",sum);
    }
    return 0;
}
