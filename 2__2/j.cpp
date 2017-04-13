#include "algorithm"
#include "cstdio"
#include "cstring"
#include "math.h"
#include "iostream"
#define eps 1e-6
using namespace std;

int n;
int times[500][500];
double x[202];
double y[202];
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool _less(double a,double b)
{
    if(b-a>=-eps)
        return true;
    else
        return false;
}
int main ()
{
    while (scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&x[i],&y[i]);
        }
        memset(times,0,sizeof(times));
        int maxnum=0;

        for(int m=1;m<=n;m++){
                    double starti,startj,endi,endj;
                    if(x[m]-2.50>=0){
                        starti=x[m]-2.50;
                    }
                    else {
                        starti=0;

                    }
                    if(x[m]+2.50<=50){
                        endi=x[m]+2.5;
                    }
                    else{
                        endi=50;
                    }
                    if(y[m]-2.50>=0){
                        startj=y[m]-2.50;
                    }
                    else {
                        startj=0;

                    }
                    if(y[m]+2.50<=50){
                        endj=y[m]+2.5;
                    }
                    else{
                        endj=50;
                    }
                for(int i=starti;i<=endi;i+=0.1){
                    for(int j=startj;j<=endj;j+=0.1){
                        times[i*10][j*10]++;
                        maxnum=max(maxnum,times[i*10][j*10]);
                    }
                }


        }



        printf("%d\n",maxnum);
    }
}
