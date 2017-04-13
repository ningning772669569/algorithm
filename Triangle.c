#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#define eps (1e-8)
#define zero(x) (((x)>0?(x):-(x))<eps)

typedef struct point3{
    double x,y,z;
}point3;

point3 xmult(point3 u,point3 v);
point3 subt(point3 u,point3 v);
point3 pvec(point3 s1,point3 s2,point3 s3);
double dmult(point3 u,point3 v);
int same_side(point3 p1,point3 p2,point3 s1,point3 s2,point3 s3);
int intersect_in(point3 l1,point3 l2,point3 s1,point3 s2,point3 s3);
int dot_inplane_ex(point3 p,point3 s1,point3 s2,point3 s3);
int dot_inplane_in(point3 p,point3 s1,point3 s2,point3 s3);
double vlen(point3 p);

int main ()
{
    int T;
    scanf("%d",&T);
    int i,j;
    int num;

    int x,y,z;
    for(i=1;i<=T;i++){
        num=0;
        point3 triangle1[4];
        point3 triangle2[4];
        for(j=1;j<=3;j++){
            scanf("%d %d %d",&x,&y,&z);
            triangle1[j].x=(double)x;
            triangle1[j].y=(double)y;
            triangle1[j].z=(double)z;

        }
        for(j=1;j<=3;j++){
            scanf("%d %d %d",&x,&y,&z);
            triangle2[j].x=(double)x;
            triangle2[j].y=(double)y;
            triangle2[j].z=(double)z;

        }
        for(j=0;j<=2;j++){
            if(intersect_in(triangle1[j],triangle1[(j+1)%3],triangle2[0],triangle2[1],triangle2[2]))
                num++;
        }
         for(j=0;j<=2;j++){
            if(dot_inplane_ex(triangle1[j],triangle2[0],triangle2[1],triangle2[2]))
                num--;
        }
        printf("%d\n",num);
        if(num==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

point3 xmult(point3 u,point3 v)
{
	point3 ret;
	ret.x=u.y*v.z-v.y*u.z;
	ret.y=u.z*v.x-u.x*v.z;
	ret.z=u.x*v.y-u.y*v.x;
	return ret;
}

point3 subt(point3 u,point3 v)
{
	point3 ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
}

point3 pvec(point3 s1,point3 s2,point3 s3)
{
	return xmult(subt(s1,s2),subt(s2,s3));
}

double dmult(point3 u,point3 v){
	return u.x*v.x+u.y*v.y+u.z*v.z;
}


int same_side(point3 p1,point3 p2,point3 s1,point3 s2,point3 s3)
{
	return dmult(pvec(s1,s2,s3),subt(p1,s1))*dmult(pvec(s1,s2,s3),subt(p2,s1))>eps;
}
int intersect_in(point3 l1,point3 l2,point3 s1,point3 s2,point3 s3)
{
    return !same_side(l1,l2,s1,s2,s3)&&!same_side(s1,s2,l1,l2,s3)&&
		!same_side(s2,s3,l1,l2,s1)&&!same_side(s3,s1,l1,l2,s2);
}
int dot_inplane_ex(point3 p,point3 s1,point3 s2,point3 s3){
	return dot_inplane_in(p,s1,s2,s3)&&vlen(xmult(subt(p,s1),subt(p,s2)))>eps&&
		vlen(xmult(subt(p,s2),subt(p,s3)))>eps&&vlen(xmult(subt(p,s3),subt(p,s1)))>eps;
}
int dot_inplane_in(point3 p,point3 s1,point3 s2,point3 s3){
	return zero(vlen(xmult(subt(s1,s2),subt(s1,s3)))-vlen(xmult(subt(p,s1),subt(p,s2)))-
		vlen(xmult(subt(p,s2),subt(p,s3)))-vlen(xmult(subt(p,s3),subt(p,s1))));
}
double vlen(point3 p){
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
