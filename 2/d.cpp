#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "vector"
#include "math.h"
#define MAX 1000000010
#define MOOR 1000000007
using namespace std;
int euler(int n);

int main ()
{
    long long N;
    cin >> N;
    while(N){
        int num;
        int re;

        num=euler(N);
        re=((N-1-euler(N))*N/2)%MOOR;
        printf("%d\n",re);
        cin >> N;
    }
    return 0;
}

int euler(int n)
{
    int m=(int) sqrt(n+0.5);
    int ans=n;
    for(int i=2;i<=m;i++) if(n%i==0){
        ans=ans/i*(i-1);
        ans%=MOOR;
        while(n%i==0)   n/=i;
    }
    if(n>1)
        ans=ans/n*(n-1);
        ans%=MOOR;
    return ans;
}
