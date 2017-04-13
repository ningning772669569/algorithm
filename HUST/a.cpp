#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int maxn=1009;
int n,m;
char a[maxn][maxn];
int dp[maxn][maxn][2];
int main ()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,'b',sizeof(a));
        for(int i=n;i>=1;i--){
            getchar();
            for(int j=1;j<=m;j++){
                scanf("%c",&a[i][j]);
            }
        }
        memset(dp,0x3f,sizeof(dp));
        dp[n][0][0]=0;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='b'){
                    dp[i][j][0]=dp[i][j-1][0]+1;
                    dp[i][j][1]=dp[i+1][j][1]+1;
                    /*if(a[i+1][j+1]=='b')
                        dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]);
                    else
                        dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
                    if(a[i-1][j]=='b')
                        dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]);
                    else
                        dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+1);*/
                }
                else{
                    dp[i][j][0]=dp[i][j-1][0];
                    dp[i][j][1]=dp[i+1][j][1];
                    if(a[i+1][j+1]=='b')
                        dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]);
                    else
                        dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
                    if(a[i-1][j]=='b')
                        dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]);
                    else
                        dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+1);
                }
            }
        }
        cout<<min(dp[1][m][0],dp[1][m][1])<<endl;

    }
    return 0;
}
