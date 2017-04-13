#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,d,e,f;
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&f,&c,&d,&e,&b)!=EOF)
    {
        a*=a;
        b*=b;
        c*=c;
        d*=d;
        e*=e;
        f*=f;

        double V=sqrt(a*b*(c+d+e+f-a-b)+c*d*(a+b+e+f-c-d)+e*f*(a+b+c+d-e-f)-a*c*e-b*d*e-a*d*f-b*c*f)/12;
        printf("%.4lf\n",V);
    }
    return 0;
}
