#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
double rs[140];
double aa[140];
int s,m,p;
int main()
{
    while(scanf("%d %d %d",&s,&m,&p)==3){
        rs[0]=s;
        aa[0]=0;
        for(int i=1;i<=m;i++){
            aa[i]=aa[i-1]+aa[i-1]*p/100-1;
            rs[i]=rs[i-1]+rs[i-1]*p/100;
        }
        printf("%lf\n",rs[m]/aa[m]*-1.0);
    }
}
