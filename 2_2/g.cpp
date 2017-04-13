#include "cstring"
#include "cstdio"
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n,k;
int num[1001];
int maxsteps=0;
int dp[1005][1005];
vector<char> process;
void init()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    dp[1][num[1]]=1;
    maxsteps=1;
    process.clear();

}
void show(int starti,int startj){
    int j=startj;
    for(int i=starti;i>0;i--){
        if(j-num[i]>=0&&dp[i-1][j-num[i]]){
            process.push_back('+');
            j=j-num[i];
            continue;
        }
        if(j+num[i]<=k&&dp[i-1][j+num[i]]){
            process.push_back('-');
            j=j+num[i];

            continue;
        }

    }
    printf("%d\n",maxsteps);
    vector<char>::size_type tep=process.size();
    for(int i=tep-1;i>=0;i--){
        printf("%c",process[i]);
    }
    printf("\n");
}
int main ()
{
    while(scanf("%d %d",&n,&k)==2){
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        init();
        for(int i=2;i<=n;i++){
            bool flag=false;
            for(int j=0;j<=k;j++){

                if(j-num[i]>=0&&dp[i-1][j-num[i]]){
                    dp[i][j]=dp[i-1][j-num[i]]+1;
                    flag=true;
                }
                if(j+num[i]<=k&&dp[i-1][j+num[i]]){
                    dp[i][j]=dp[i-1][j+num[i]]+1;
                    flag=true;
                }

            }
            if(flag)
                    maxsteps++;
        }
        int startj,starti;

            for(int j=0;j<=k;j++){
                if(dp[maxsteps][j]){
                    starti=maxsteps;
                    startj=j;
                    break;
                }

            }
            show(starti,startj);

    }
}
