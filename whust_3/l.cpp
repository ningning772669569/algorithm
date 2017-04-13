#include "algorithm"
#include "cstdio"
#include "iostream"
#include "cstring"
using namespace std;
int n,w;
int capa[200001];
int cmp(int a,int b)
{
    return a<b;
}
int main ()
{
    while (scanf("%d %d",&n,&w)==2){
        for(int i=1;i<=2*n;i++){
            scanf("%d",&capa[i]);
        }
        double re;
        sort(capa+1,capa+2*n+1);
        double ming=capa[1]*1.0;
        double minb=capa[n+1]*1.0;
        if(minb>2*ming){
            minb=2*ming;
        }
        else{
            ming=minb/2;
        }
        if(ming*3*n<w){
            re=ming*3*n;
        }
        else{
            re=w;
        }
        printf("%lf\n",re);
    }
}
