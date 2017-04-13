#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
double s,p;
int m;
double rs[130];
int main ()
{
    while(scanf("%lf %d %lf",&s,&m,&p)==3){
        double sum=1;
        p=p/100*1.0;
        for(int i=1;i<=m;i++){
            sum=sum*(1+p);
        }
        double tep;
        tep=sum-1;
        double x;
        x=sum*p/tep*s;
        printf("%lf\n",x);
    }
}
