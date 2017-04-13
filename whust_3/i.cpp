#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
int n,p,q;
int main ()
{
    int caseid=0;
    while (scanf("%d %d %d",&n,&p,&q)==3){
        double re=0;
        for(int i=q;i<=n-p+q;i++){
            re=re+1.0*(i-q)/(n-p);
        }
        re=re/(n-p+1);
        caseid++;
        printf("Case %d: %.4lf\n",caseid,re);
    }
    return 0;
}
