#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n,k,l,r,sall,sk;
int num[1020];
int dfs2(int high,int pos,int sum)
{
    if(pos==n){
        if(sum>=l&&sum<=high){
        num[pos]=sum;
        return 1;
        }
        else{
            return 0;
        }
    }

    for(int i=high;i>=l;i--){
        if(dfs2(i,pos+1,sum-i)){
            num[pos]=i;
            return 1;
        }
    }
    return 0;

}
void dfs(int low,int pos,int sum)
{
    if(pos==k){
        num[pos]=sum;
        return ;
    }
    for(int i=low;i<=r;i++){
        if((k-i)*r>=sum&&(k-i)*low<=sum){
            num[pos]=i;
            dfs(i,pos+1,sum-i);
            break;
        }
    }
}
int main ()
{
    while(scanf("%d %d %d %d %d %d",&n,&k,&l,&r,&sall,&sk)==6){
        int sum=sall-sk;
        int low;
        for(int i=l;i<=r;i++){
            if(i*(n-k)>=sum){
                low=i;
            }
        }
        if(k<n)
            dfs2(low,k+1,sum);
        dfs(low,1,sk);
        for(int i=1;i<=n;i++){
            printf("%d",num[i]);
            if(i<n) printf(" ");
        }
        printf("\n");
    }
}
