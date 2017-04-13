#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#define MAXN 505
#define MAXW 10010
#define INF 99999999
using namespace std;
typedef long long LL;
int E,F;
int N;
int v[MAXN];
int w[MAXN];
int dp[MAXW];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&E,&F);
        int W=F-E;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d %d",&v[i],&w[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=w[1];i<=W;i+=w[1])
            dp[i]=v[1]*(i/w[1]);

        for(int i=2;i<=N;i++){
            int times;

            for(int j=W;j>=0;j--){
                    int _min=INF;
                    if(dp[j])  _min=dp[j];
                    if(j>=w[i]){
                        times=j/w[i];
                        for(int tep=1;tep<=times;tep++){

                                if(j-tep*w[i]!=0){
                                    if(dp[j-tep*w[i]])
                                        _min=min(_min,dp[j-tep*w[i]]+tep*v[i]);


                                }
                                else {
                                        _min=min(_min,tep*v[i]);
                                }
                        }
                        if(_min!=INF)
                        dp[j]=_min;
                        else    dp[j]=0;
                    }
            }
        }
        if(dp[W])
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);
        else
            printf("This is impossible.\n");
    }
    return 0;
}

