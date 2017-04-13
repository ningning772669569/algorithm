#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n;
int have[15];
int need[15];
int cost[15];
int main ()
{
    while (scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&have[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&need[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&cost[i]);
        }
        int maxnum=0;
        for(int i=1;i<=n;i++){
            int num=have[i]/need[i];
            if(have[i]%need[i])
                num++;
            maxnum=max(maxnum,num);
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+(need[i]*maxnum-have[i])*cost[i];
        }
        printf("%d\n",sum);
    }
}
