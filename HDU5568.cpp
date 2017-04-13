#include <cstdio>
#include <cstring>
#include <algorithm>

#define LEN 110
#define MOD 100000000

using namespace std;

struct BigInt {//随便找了个高精度模版，不会手写...
    int len,p[LEN];
    BigInt() {
        memset(p,0,sizeof(p));
        len=0;
    }
}dp[105][105],ans;//dp[i][j]表示以第i个数为终止数的一个长度为j的序列的不同方案数

int a[105],s,num,n,k,t;

BigInt add(const BigInt& x,const BigInt& y) {
    BigInt cnt;
    t=max(x.len,y.len);
    for(int i=1;i<=t;i++) {
        cnt.p[i]+=x.p[i]+y.p[i];
        cnt.p[i+1]=cnt.p[i]/MOD;
        cnt.p[i]%=MOD;
    }
    if(cnt.p[t+1])
        t++;
    cnt.len=t;
    return cnt;
}

void print(const BigInt& x) {
    printf("%d",x.p[x.len]);
    for(int i=x.len-1;i>=1;i--)
        printf("%08d",x.p[i]);
    printf("\n");
}

int main() {
    int i,j,x;
    while(scanf("%d%d",&n,&k)==2) {
        memset(dp,0,sizeof(dp));
        memset(ans.p,0,sizeof(ans.p));
        ans.len=0;
        for(i=0;i<n;++i) {
            scanf("%d",a+i);
            dp[i][1].p[1]=dp[i][1].len=1;
        }
        for(i=1;i<n;++i)
            for(j=0;j<i;++j)
                if(a[i]>a[j])//只有当前a[i]>a[j]时才进行状态转移
                    for(x=1;x<n;++x)
                        dp[i][x+1]=add(dp[i][x+1],dp[j][x]);
        for(i=0;i<n;++i)
            ans=add(ans,dp[i][k]);
        print(ans);
    }
    return 0;
}
