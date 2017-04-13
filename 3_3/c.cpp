#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
using namespace std;
int cmp(double a,double b)
{
    return a>b;
}
int n,i,j,k;
int main()
{

    double pro[110],sum,re;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf",&pro[i]);
    sort(pro,pro+n,cmp);
    re=0;
    for(i=1;i<=n;i++)
    {
        double x;
        sum=0;
        for(j=0;j<i;j++)
        {
            x=pro[j];
            for(k=0;k<i;k++)
            {
                if(j!=k)
                    x*=1-pro[k];
            }
            sum+=x;
        }
        re=max(sum,re);
    }
    printf("%.10lf\n",re);
}
