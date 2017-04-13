#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "queue"
using namespace std;
typedef long long LL;
LL n,x;
int num[500005];
LL sum[500005];
int ans;
struct node{
    int pos;
    LL sum;
    node(LL sum,int pos):sum(sum),pos(pos){}
};
deque<struct node> q;
void in(int i)
{
    if(q.back().sum<sum[i]){
        struct node tep(sum[i],i);
    }
    else{
        deque<struct node>::iterator iter=q.end();
        iter--;
        while((*iter).sum>=sum[i]){
            iter--;
        }
        while(q.end()!=(iter+1)){
            if(q.back().sum-(*iter).sum>=x){
                deque<struct node>::iterator tepiter=iter;
                while(q.back().sum-(*tepiter).sum>=x){
                    ans=min(ans,q.back().pos-(*tepiter).pos);
                    tepiter++;
                }

            }
            q.pop_back();
        }
        struct node tepnode(sum[i],i);
        q.push_back(tepnode);

    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%lld %lld",&n,&x);
        ans=0x3f3f3f3f;
        while(!q.empty())
            q.pop_back();
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        for(int i=1;i<=n;i++){
            sum[i]=num[i]+sum[i-1];
        }
        for(int i=1;i<=n;i++){
            in(i);
        }
        printf("%d\n",ans);
    }
}
