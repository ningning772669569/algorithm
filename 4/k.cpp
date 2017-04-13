#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#define MAX 105
#define INF 1000000000
using namespace std;
typedef long long LL;
LL dp[MAX][MAX];
LL _map[MAX][MAX];
int R,C;

LL get_dp (int i,int j)
{
    if(dp[i][j])
        return dp[i][j];
    else{
        //if(_map[i][j]<_map[i-1][j]&&_map[i][j]<_map[i+1][j]&&_map[i][j]<_map[i][j-1]&&_map[i][j]<_map[i][j+1])
            //return 1;
        int l=0,r=0,u=0,d=0;
        if(i>1&&_map[i][j]>_map[i-1][j])
            u=get_dp(i-1,j);
        if(i<R&&_map[i][j]>_map[i+1][j])
            d=get_dp(i+1,j);
        if(j>1&&_map[i][j]>_map[i][j-1])
            l=get_dp(i,j-1);
        if(j<C&&_map[i][j]>_map[i][j+1])
            r=get_dp(i,j+1);
        dp[i][j]=max(max(u,d),max(l,r))+1;
        return dp[i][j];
    }
}
int main ()
{
    //int R,C;
    while (scanf("%d %d",&R,&C)==2){
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                _map[i][j]=INF;
            }
        }
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                scanf("%I64d",&_map[i][j]);

            }

        }
        memset(dp,0,sizeof(dp));
        int top;
        top=0;
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                int tmp=get_dp(i,j);
                if(top<tmp)
                    top=tmp;

            }
        }
        printf("%d\n",top);
    }
}
