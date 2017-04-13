#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define mod 1000000007
const int INF = 1<<30;
const int N = 810;
int dp[N][N];
pair<int,int> pr[N];
bool cmp(pair<int,int> i, pair<int,int> j) {return i>j;}
int main()
{
    int T, n;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d%d", &pr[i].S,&pr[i].F);
        sort(pr+1,pr+n+1,cmp);
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i/2; j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]+pr[i].S);
            }
        }
        printf("%d\n", dp[n][n/2]);
    }
    return 0;
}
