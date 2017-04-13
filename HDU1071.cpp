#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
double x1,y1,x2,y2,x3,y3;
double geta()
{
    return (y2-y1)/((x2-x1)*(x2-x1));
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double a,b,c;
        double k,d;
        a=geta(); b=x1;c=y1;
        k=(y3-y2)/(x3-x2);
        d=y2-k*x2;
        double re=0.0;
        //cout<<a<<" "<<b<<" "<<c<<" "<<k<< " "<<d<<endl;
        re+=a/3*(x3*x3*x3-x2*x2*x2);
        re+=(2*a*b+k)/2*(x2*x2-x3*x3);
        re+=(a*b*b+c-d)*(x3-x2);
        printf("%.2lf\n",re);
    }
    return 0;
}
