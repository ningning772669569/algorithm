#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int T;
int sum;
int check(double len,double wid,double dep,double wei)
{
    if(wei>7.0)
        return 0;
    if(len<=56&&wid<=45&&dep<=25)
        return 1;
    if(len+wid+dep<=125)
        return 1;
    return 0;
}
int main ()
{
    double len,wid,dep,wei;
    sum=0;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%lf %lf %lf %lf",&len,&wid,&dep,&wei);
        if(check(len,wid,dep,wei)){
            printf("1\n");
            sum++;
        }
        else{
            printf("0\n");
        }
    }
    printf("%d\n",sum);
    return 0;
}
