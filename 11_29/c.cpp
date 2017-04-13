#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=810;
struct node{
    int a,b;
};
node cake[maxn];
int N;
int dp[maxn][maxn];
int cmp(const struct node &p,const node &q)
{
    if(p.b!=q.b){
        return p.b>q.b;
    }
    else{
        return p.a>q.a;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d%d",&cake[i].a,&cake[i].b);
        }
        sort(cake+1,cake+1+N,cmp);
        /*for(int i=1;i<=N;i++)
            cout<<cake[i].b<<endl*/;
        memset(dp,0,sizeof(dp));
        //dp[1][1]=cake[1].a;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=i/2;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+cake[i].a);
            }
        }
        cout<<dp[N][N/2]<<endl;
    }
}
