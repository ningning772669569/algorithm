#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
#include "math.h"
const double eps =1e-10;
struct point {
    double x,y;

    point(double x=0,double y=0):x(x),y(y){}
};
typedef point Vector;
struct line {
    point p;
    Vector v;
    double ang;
    line (){}
    line(point p,Vector v):p(p),v(v){ang=atan2(v.y,v.x);}
    bool operator < (const struct line & l) const {
    return ang<l.ang;
    }
};
int dcmp (double x)
{
    if(fabs(x)<eps)
        return 0;
    else
        return x<0? -1 :1;
}
Vector operator - (point a,point b)
{
    return Vector(a.x-b.x,a.y-b.y);
}
double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
bool onsegment(point p,point a1,point a2)
{
    return dcmp(cross(a1-p,a2-p))==0&& dcmp(dot(a1-p,a2-p))<0;
}

point getlineintersection (point p,Vector v,point q,Vector w)
{
    Vector u=p-q;
    double t=cross(w,u)/cross(v,w);
    return p+v*t;
}
polygon cutpolygon(polygon poly,point a,point b)
{
    polygon newpoly;
    int n=poly.size();
    for(int i=0;i<n;i++){
        point c=poly[i];
        point d=poly[(i+1)%n];
        if(dcmp(cross(b-a,c-a)>=0)) newpoly.push_back(C);
        if(dcmp(cross(b-a,c-d)!=0)){
            point ip=getlineintersction(a,b-a,c,d-c);
            if(onsegment(ip,c,d))   newpoly.push_back(ip);
        }
    }
    return newpoly;
}
int main ()
{

}
