#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int maxn=1e5+200;
typedef long long LL;
LL p[maxn];
LL q[maxn];
LL r[maxn];
int P,Q,R;
LL num[maxn];
LL sum[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        memset(r,0,sizeof(r));
        memset(sum,0,sizeof(sum));
        memset(num,0,sizeof(num));
        scanf("%d",&P);
        for(int i=0;i<P;i++){
            scanf("%I64d",&p[i]);
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%I64d",&q[i]);
        }
        scanf("%d",&R);
        for(int i=0;i<R;i++){
            scanf("%I64d",&r[i]);
        }
        for(int i=0;i<Q&&i<R;i++){
            LL * a=lower_bound(r+i,r+R,q[i]);
            num[i]=R-(a-r);
        }
        for(int i=Q-1;i>=0;i--){
            sum[i]=sum[i+1]+num[i];
        }
        LL all=0;
        for(int i=0;i<P&&i<Q;i++){
            LL * a=lower_bound(q+i,q+Q,p[i]);
            all+=sum[a-q];
        }
        printf("%I64d\n",all);

    }
}
