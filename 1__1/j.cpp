#include "cstdio"
#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;
int N,X;
int num[500005];
int mini[500005];
struct Sum{
    int pos;
    int sum;
};
struct Sum sum[500005];
int cmp1(const struct Sum &p,const struct Sum &q)
{
    return p.sum<q.sum;
}
int cmp2(const struct Sum &p,const struct Sum &q)
{
    return p.sum>q.sum;
}
int _find(int num)
{
    int from=1;
    int to=N;
    int mid=(from+to)/2;
    while(from<to){
        if(sum[mid].sum==num)
            return mid;
        else if(sum[mid].sum<num){
            from=mid+1;
        }
        else{
            to=mid-1;
        }
    }
    return from;
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&N,&X);
        int tepsum=0;
        int minsum=99999999;
        for(int i=1;i<=N;i++){
            scanf("%d",&num[i]);
            tepsum=tepsum+num[i];
            if(tepsum<minsum)
                minsum=tepsum;
            sum[i].sum=tepsum;
            sum[i].pos=i;
        }
        if(X>0)
            sort(sum+1,sum+N+1,cmp1);
        else{
            sort(sum+1,sum+N+1,cmp2);
        }
        int MIN=N+1;
        for(int i=N;i>=1;i--){
            if(sum[i].pos>MIN)
                mini[i]=MIN;
            else{
                MIN=sum[i].pos;
            }

        }
        int re=N;
        for(int i=1;i<=N;i++){
            int pos=_find(sum[i].sum+X);

            for(int j=pos;j<=N;j++){
                if(abs(sum[j].sum-sum[i].sum)>abs(X)){
                    if(i<mini[j])
                        re=min(re,mini[j]-i);

                }
            }
        }
    }
}
