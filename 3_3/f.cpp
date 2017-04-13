#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n,k,l,r,sall,sk;
int num[1020];

void dfs(int low,int pos,int sum)
{
    if(pos==k){
        num[pos]=sum;
        return ;
    }
    for(int i=low;i<=r;i++){
        if((k-pos)*r>=sum-i&&(k-pos)*low<=sum-i){
            num[pos]=i;
            dfs(i,pos+1,sum-i);
            break;
        }
    }
}
void dfs2(int high,int pos,int sum)
{
    if(pos==n){
        num[pos]=sum;
        return ;
    }
    for(int i=high;i>=l;i--){
        if((n-pos)*high>=sum-i&&(n-pos)*l<=sum-i){
            num[pos]=i;
            dfs2(i,pos+1,sum-i);
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
                break;
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

