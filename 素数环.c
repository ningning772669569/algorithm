#include "stdio.h"
#include "stdlib.h"
#define MAX 30
int* make_prime_list(int);
int is_prime(int,int []);
void dfs (int,int,int []);

int num[MAX+1];
int is_used[MAX+1];
int main ()
{
    int *prime =make_prime_list(20);
    dfs(1,5,prime);
    return 0;
}

int* make_prime_list(int n)
{
    int i,j;
    int * prime=(int *)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++){
        prime[i]=1;
    }///初始化素数的数组
    for(i=2;i<=n;i++){
        if(prime[i]){
            for(j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }

    }
    return prime;
}
int is_prime(int num,int prime[])
{
    if(prime[num])
        return 1;
    else
        return 0;
}
void dfs (int n,int limit,int prime[])
{
    int i,j;
    if(n==limit&&is_prime(num[n]+num[1],prime)){
        for(i=1;i<=n;i++){
            printf(" %d ",num[i]);
        }
        printf("\n");
    }
    else{
        for(i=1;i<=limit;i++){
            if(!is_used[i]&&is_prime(i+num[n-1],prime)){
                num[n]=i;
                is_used[i]=1;
                dfs(n+1,limit,prime);
                is_used[i]=0;///注意要在回溯中奖设置的全局辅助变量还原，保证回到上一层的时候辅助变量是对应的，而不会
                ///因为下面的执行导致辅助变量不同
            }
        }
    }
}
