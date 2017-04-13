#include"stdio.h"
#include "stdlib.h"
#include "math.h"
int main ()
{
    int a,b,c;
    int i;
    int T;
    double x1,x2;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d %d %d",&a,&b,&c);
        int d=b*b-4*a*c;
        double sd;
        double tep1,tep2,tep3;
        if(d<0){
            printf("NO\n");
        }
        else if(d==0){

            tep1=-1.0*b;
            tep2=2.0*a;
            sd=tep1/tep2;
            printf("%.2f\n",sd);
        }
        else{
            tep1=1.0*d;
            sd=sqrt(tep1);
            tep1=-1.0*b;
            tep2=2.0*a;
            tep3=tep1+sd;
            x1=tep3/tep2;
            tep3=tep1-sd;
            x2=tep3/tep2;
            if(x1>x2)
             {
                tep1=x1;
                x1=x2;
                x2=tep1;
             }


            printf("%.2f %.2f\n",x1,x2);
        }
    }
    return 0;
}
