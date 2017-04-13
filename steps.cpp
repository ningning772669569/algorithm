#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL x,y;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%I64d %I64d",&x,&y);
        LL dis=y-x;
        if(dis==1){
            printf("1\n");
            continue;
        }
        else if(dis==0){
            printf("0\n");
            continue;
        }
        else  if(dis==2){
            printf("2\n");
            continue;
        }
        else{
            LL times=2;
            LL add=2;
            LL re=2;
            while(times<dis){
                if(times+2*add<dis){
                    times+=2*add;
                    add++;
                    re+=2;
                }
                else if(times+add<dis){
                    re+=2;
                    break;
                }
                else if(times+add>=dis){
                    re++;
                    break;
                }
            }
            printf("%lld\n",re);

        }
    }
}
