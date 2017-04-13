#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "cmath"
#define MAX 500005
using namespace std;
int sum[MAX];
int N,X;
int dp[MAX][20];
void RMQ()
{
    for(int i=1;i<=N;i++){
        dp[i][0]=sum[i];

    }
    for(int j=1;(1<<j)<=N;j++){
        for(int i=1;i+(1<<j)-1<=N;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }

}
int query(int l,int r)
{
    int k=0;
    while((1<<(k+1)<=(r-l+1)))k++;
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main ()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(sum,0,sizeof(sum));
        scanf("%d %d",&N,&X);
        sum[0]=0;
        int num;
        for(int i=1;i<=N;i++){
            scanf("%d",&num);
            sum[i]=sum[i-1]+num;
        }
        RMQ();
        int ans=99999999;
        bool havefind=false;
        for(int i=1;i<=N;i++){
            int left=i+1,right=N;
            int mid;
            while(left<right){
                mid=(left+right)>>1;
                if(query(left,mid)-sum[i]>=X)
                    right=mid;
                else
                left=mid+1;
            }
            if(sum[right]-sum[i]>=X){
                havefind = true;
                ans=min(ans,right-i);
            }

        }
        if(havefind)
            printf("%d\n",ans);
        else {
            printf("-1\n");
        }
    }
}
