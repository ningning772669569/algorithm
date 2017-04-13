#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
#define eps (1e-8)
using namespace std;
int N,M;
struct node{
    double x,y;

};
node nodes[110];
double dis[110];
double getdis(int i,int j)
{
    return sqrt((nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x)+(nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y));
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
       scanf("%d %d",&M,&N);
       for(int i=1;i<=M;i++){
            scanf("%lf %lf",&nodes[i].x,&nodes[i].y);
       }
       if(N>M){
        printf("-1\n");
        continue;
       }
       int MIN=999999;
       for(int i=1;i<=M;i++){
            memset(dis,0,sizeof(dis));
            int disnum=0;
            for(int j=1;j<=M;j++){
                if(j==i)
                    continue;
                disnum++;
                double tepdis=getdis(i,j);
                dis[disnum]=tepdis;
            }
            sort(dis+1,dis+M);
            double tepre=dis[N-1];
            int tt=tepre;
            double * check=lower_bound(dis+1,dis+M,tt+1);
            if(check-dis<M){
                if((*check)-tt-1<=eps)
                    continue;
            }
            if(check-dis>N)
                continue;
            MIN=min(MIN,tt+1);


       }
       if(MIN!=999999)
        printf("%d\n",MIN);
       else{
        printf("-1\n");
       }
    }
}
