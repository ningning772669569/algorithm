#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#define  INF 9999999
using namespace std;
int n,m;
int need[1005];
int have[10000];
int left[10000];
int remain;
int rooms;
int month;
void init()
{
    memset(need,0,sizeof(need));
    remain =0;
    rooms=0;
    month=0;
    need[n+1]=INF;

}
int main ()
{
    while(scanf("%d %d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            scanf("%d",&need[i]);
        }
        init();
        while(1){
            if(rooms==n){
                break;
            }
            month++;
            remain=remain+m;
            while(remain>=need[rooms+1]){
                remain=remain-need[rooms+1];
                rooms++;
            }
            left[month]=remain;
            have[month]=rooms;
        }
    }
    return 0;
}
