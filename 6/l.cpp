#include "algorithm"
#include "cstdio"
#include "cstring"
#include "math.h"
#include "iostream"
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
struct point {
    double x,y;
    point (double x=0,double y=0):x(x),y(y){}
};
struct line {
    point a,b;
};
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
int dot_online_in(point p,point l1,point l2){
	return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}
int same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}
int intersect_in(point u1,point u2,point v1,point v2)
{
    if(!dots_inline(u1,u2,v1)||!dots_inline(u1,u2,v2))
        return !same_side (u1,u2,v1,v2)&&!same_side(v1,v2,u1,u2);
    return dot_online_in(u1,v1,v2)||dot_online_in(u2,v1,v2)||dot_online_in(v1,u1,u2)||dot_online_in(v2,u1,u2);
}
int main ()
{
    int T;
    cin>> T;
    for(int i=1;i<=T;i++){
        point a,b;
        int x,y;
        int x2,y2;
        int ta,tb,tc,td;
        scanf("%d %d",&x,&y);
        a.x=x;
        a.y=y;
        scanf("%d %d",&x,&y);
        b.x=x;
        b.y=y;
        scanf("%d %d",&ta,&tb);
        scanf("%d %d",&tc,&td);
        x=min(ta,tc);
        x2=max(ta,tc);
        y=max(tb,td);
        y2=min(tb,td);
        point c,d;
        if(a.x>=x&&a.x<=x2&&a.y<=y&&a.y>=y2){
            printf("T\n");
            continue;
        }
        if(b.x>=x&&b.x<=x2&&b.y<=y&&b.y>=y2){
            printf("T\n");
            continue;
        }
        c.x=x;c.y=y;
        d.x=x2;d.y=y;

        if(intersect_in(a,b,c,d)){
            printf("T\n");
            continue;
        }
        c.x=x2;c.y=y;
        d.x=x2;d.y=y2;
        if(intersect_in(a,b,c,d)){
            printf("T\n");
            continue;
        }
        c.x=x;c.y=y2;
        d.x=x2;d.y=y2;
        if(intersect_in(a,b,c,d)){
            printf("T\n");
            continue;
        }
        c.x=x;c.y=y;
        d.x=x;d.y=y2;
        if(intersect_in(a,b,c,d)){
            printf("T\n");
            continue;
        }
        printf("F\n");
    }
    return 0;
}
