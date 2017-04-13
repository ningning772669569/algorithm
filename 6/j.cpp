#include "algorithm"
#include "math.h"
#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;
const double eps = 1e-8;
const double pi  = acos(-1.0);
double r,R, x_1,x_2,y_1,y_2;
struct point {
    double x,y;
    point (double x=0,double y=0):x(x),y(y){}
};
struct circle{
    point c;
    double r;
    circle(point c,double r):c(c),r(r){}
};
double area(point a, double r1, point b, double r2)
{
    double d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if (d >= r1+r2)
        return 0;
    if (r1>r2)
    {
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    if(r2 - r1 >= d)
        return pi*r1*r1;
    double ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
    double ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
    return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}
int main ()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        scanf("%lf %lf",&r,&R);
        scanf("%lf %lf",&x_1,&y_1);
        scanf("%lf %lf",&x_2,&y_2);
        point a,b;
        a=point(x_1,y_1);
        b=point(x_2,y_2);

        printf("Case #%d: %lf\n",t,area(a,R,b,R)+area(a,r,b,r)-area(a,R,b,r)-area(a,r,b,R));
    }
    return 0;
}
