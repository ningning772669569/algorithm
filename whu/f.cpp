#include <stdio.h>
int main ()
{
    int l,a,b,d,dir;
    while(scanf("%d%d%d%d%d",&l,&a,&b,&d,&dir)==5){
        double re;
        re=d/(0.5*l);
        if(re>1.0)
            re=1.0;
        printf("%6lf\n",re);
    }
    return 0;
}
