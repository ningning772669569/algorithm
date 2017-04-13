#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n,k,l,r,all,sk;

int a[3433];
int res[23432]={0};
int main()
{
    while(cin>>n>>k>>l>>r>>all>>sk)
    {
        int i,j;
        if(k==n)

        for( i=0;i<sk%k;i++)
        {
            cout<<sk/k+1<< ' ';
        }
        for(;i<k;i++)
            cout<<sk/k<<' ';
        all-=sk;
        n-=k;
        if(n==0)continue;   ///开始没有这句，被hack了！！！
        for(i=0;i<all%n;i++)    ///N！=0
            cout<<all/n+1<<" ";
        for(;i<n;i++)
            cout<<all/n<<' ';
    }
}
