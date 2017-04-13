#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;
typedef long long LL;
int num[2000005];
int sum[2000005];
struct node {
    LL sum;
    int pos;
    node(LL s,int a):sum(s),pos(a){}
};
int n;
int re;
deque<struct node> q;
void qin(int i)
{
    while(!q.empty()&&q.back().sum>sum[i]){
        q.pop_back();
    }
    struct node tep(sum[i],i);
    q.push_back(tep);
}
void check(int i)
{
    if(i-q.front().pos>=n){
        re++;
        q.pop_front();
    }
}
int main ()
{
    while(scanf("%d",&n)!=EOF&&n){
        re=0;
        while(!q.empty())
            q.pop_back();
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            num[i+n]=num[i];
        }
        for(int i=1;i<=2*n;i++){
            sum[i]=sum[i-1]+num[i];
        }
        for(int i=1;i<=n;i++){
            qin(i);
        }
        for(int i=n+1;i<=2*n;i++){
            qin(i);
            check(i);
        }
        printf("%d\n",re);
    }
}
