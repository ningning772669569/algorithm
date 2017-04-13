#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
#include <math.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
double getdis(double a,double b,double c,double x,double y,double z)
{
    return sqrt((a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z));
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        double tepx,tepy,tepz;
        double xmin=99999999,xmax=0,ymin=99999999,ymax=0,zmin=999999999,zmax=0;
        for(int i=1;i<=8;i++){
            scanf("%lf %lf %lf",&tepx,&tepy,&tepz);
            if(xmin>tepx)
                xmin=tepx;
            if(xmax<tepx)
                xmax=tepx;
            if(ymin>tepy)
                ymin=tepy;
            if(ymax<tepy)
                ymax=tepy;
            if(zmin>tepz)
                zmin=tepz;
            if(zmax<tepz)
                zmax=tepz;
        }
        double cx,cy,cz;
        double r;
        scanf("%lf %lf %lf",&cx,&cy,&cz);
        scanf("%lf",&r);
        double x,y,z;
        if(cx>=xmin&&cx<=xmax){
            x=cx;
        }
        else if(cx>xmax){
            x=xmax;
        }
        else
            x=xmin;

        if(cy>=ymin&&cy<=ymax){
            y=cy;
        }
        else if(cy>ymax){
            y=ymax;
        }
        else
            y=ymin;

        if(cz>=zmin&&cz<=zmax){
            z=cz;
        }
        else if(cz>zmax){
            z=zmax;
        }
        else
            z=zmin;
        double dis=getdis(x,y,z,cx,cy,cz);
        if(dis<=r){
            printf("Yes\n");
        }
        else
            printf("No\n");

    }
}
