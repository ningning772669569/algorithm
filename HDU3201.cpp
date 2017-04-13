#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int main ()
{
    int L;
    while(scanf("%d",&L) && L){
        double r=L/3.1415927;
        printf("%.2lf\n",0.5*3.1415927*r*r);
    }
    return 0;
}
