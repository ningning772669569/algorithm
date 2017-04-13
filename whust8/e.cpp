#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
int n;
int c[100000000];
int main ()
{
    while (scanf("%d",&n)!=EOF){
        int num=0;
        while(n){
            if(n&1)
                num++;
            n=n/2;
        }
        int sum=1;
        for(int i=1;i<=num;i++)
            sum=sum*2;
        printf("%d\n",sum);
    }
}
