#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int N;
double p[30];
int main ()
{
    while(scanf("%d",&N)!=EOF){
        for(int i=0;i<N;i++){
            scanf("%lf",&p[i]);

        }
        double re=0;
        for(int i=1;i<(1<<N);i++){
            double tep=0;
            int num=0;
            for(int j=0;j<N;j++){
                if(i & (1<<j)){
                      num++;
                      tep+=p[j];
                }
            }

            if(num&1)
                re+=1/tep;
            else
                re-=1/tep;
        }
        printf("%lf\n",re);
    }
}
