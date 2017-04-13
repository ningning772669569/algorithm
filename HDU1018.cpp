#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;

int main ()
{
    int T;
    scanf("%d",&T);

    for(int t=1;t<=T;t++){
        int num;
        scanf("%d",&num);
        long double tep=0;
        for(int i=1;i<=num;i++){
            tep+=log10(i);
        }
        int re=ceil(tep);
        printf("%d\n",re);

    }


}
