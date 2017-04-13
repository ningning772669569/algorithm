#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#define  INF 9999999
using namespace std;
int n,m;
int need[1005];
int have[100001];
int _left[100001];
int remain;
int rooms;
int month;
int q;
void init()
{

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
            _left[month]=remain;
            have[month]=rooms;
        }
        for(int i=month;i<=100000;i++){
            _left[i]=_left[month];
            have[i]=have[month];
        }
        scanf("%d",&q);
        while(q--){
            int tep;
            scanf("%d",&tep);
            printf("%d %d\n",have[tep],_left[tep]);

        }
    }
    return 0;
}
