#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int dp[100010];
int num[100010];
int bsearch(int c[],int n,int a)
{

    int l=1, r=n;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if( a > c[mid] && a <= c[mid+1] )
            return mid+1;
        else if( a < c[mid] )
           r = mid-1;
        else l = mid+1;
    }

}
int LIS(int a[], int n)
{

    int i, j, size = 1;
    int *c=new int[n+1];

    c[1] = a[1]; dp[1] = 1;

    for(i=2;i<=n;++i)
    {
        if( a[i] <= c[1] ) j = 1;
        else if( a[i] >c[size] )
            j=++size;
        else
            j = bsearch(c, size, a[i]);
        c[j] = a[i]; dp[i] = j;
    }
    return size;

}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int N,L;
        scanf("%d %d",&N,&L);
        for(int i=1;i<=N;i++){
            scanf("%d",&num[i]);

        }
        LIS(num,N);
        int MIN=dp[L]-dp[1];
        int start=1;
        for(int i=1;i+L+1<=N;i++){
            if(dp[i+L+1]-dp[i]<MIN){
                start=i;
            }

        }
        for(int i=start;i<=start+L+1;i++){
            num[i]=1e9;
        }
        int re=LIS(num,N);
        printf("Case #%d: %d\n",t,re);

    }

}
