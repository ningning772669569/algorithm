#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "queue"
#define MAX 100005
using namespace std;
typedef pair<int,int> pi;
int N;
int num[MAX];
int dp[MAX];
int main ()
{
    while (scanf("%d",&N)!=EOF){
        priority_queue<pi> q;
        vector<pi>  p;

        for(int i=1;i<=N;i++){
            scanf("%d",&num[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        q.push(make_pair(dp[1],1));
        for(int i=2;i<=N;i++){

            pi u =q.top();
            while(num[u.second]>=num[i]){
                p.push_back(u);
                q.pop();
                u=q.top();
            }
            if(!q.empty())
            dp[i]=u.first+1;
            else dp[i]=1;
            q.push(make_pair(dp[i],i));
            while(p.empty()){
                q.push(p[p.size()-1]);
                p.pop_back();

            }
        }
        printf("%d\n",q.top());
    }
    return 0;
}
