#include "stdio.h"
int main ()
{
    int i,j;
            int n;
            double step;
            double L,result;
            n = 10;
            step = (double)(10.0 / n);
            printf("%f\n\n\n",step);
            double x,xj;
            double y[n+1] ;
            for (i = 0; i <= n; i++) {
                x=(double)(-5.0+i*step);
                y[i] = (double)(1.0 / (1.0 + (x * x)));
                //printf("%f\n" ,y[i]);
            }
            result = 0.0;
                L = 1.0;
            for (i = 0; i <=n; i++) {
                x = (double)(-5.0 + step * i);
                //printf("%f\n",x);
                for (j = 0; j <= n; j++) {
                    xj = (double)(-5.0 + j * step);
                    if (j != i) {
                            //printf("%f ",xj);
                        L = (L * (4.8 - xj) / (x - xj));
                        //printf("%f\n ",x);
                    }
                }
                result += (double)(y[i] * L);
            }
            printf("%f",result);
}

