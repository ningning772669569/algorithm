#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "math.h"
using namespace std;
const double eps=1e-5;
int l,v1,v2,t;
double get(double a,double b)
{
    int geshu=(int)(a/b);
    return fabs(a-b*geshu);
}
int main ()
{
    while(scanf("%d %d %d %d",&l,&v1,&v2,&t)==4){
        if((v1+v2)*t<l){
            printf("0\n");
        }
        else if((v1+v2)*t==l){
            printf("1\n");
        }
        if(v1<v2){
            swap(v1,v2);
        }
        double t1=l/v1*1.0;
        double t2=l/v2*1.0;

        int num=(int)(t/t1);
        int numr=0;
        for(double ttep=t1;ttep<=t;ttep+=2*t1){
            double a=v2*ttep;
            if(get(a,2.0*l)<eps){
                numr++;
            }
        }
        int numl=0;
        for(double ttep=0;ttep<=t;ttep+=2*t1){
            double a=v2*ttep;
            if(fabs(get(a,2.0*l)-l)<eps){
                numl++;
            }
        }
        printf("%d\n",num-numl-numr);
    }
}

