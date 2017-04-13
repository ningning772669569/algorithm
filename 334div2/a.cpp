#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int m[10];
int w[10];
int re[10];
int s[6]={0,500,1000,1500,2000,2500};
int a,b;
int main ()
{
    for(int i=1;i<=5;i++)
        scanf("%d",&m[i]);
    for(int i=1;i<=5;i++)
        scanf("%d",&w[i]);
    scanf("%d%d",&a,&b);
    for(int i=1;i<=5;i++){
        re[i]=s[i]/10*3;
        int tep=s[i]-(s[i]/250)*m[i]-50*w[i];
        re[i]=max(re[i],tep);
    }
    int sum=0;
    for(int i=1;i<=5;i++)
        sum+=re[i];
    sum+=100*a;
    sum-=50*b;
    /*if(sum<0)
        sum=0;*/
    cout<<sum<<endl;
    return 0;
}
