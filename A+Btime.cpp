#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    int ah,am,as,bh,bm,bs,rh,rm,rs;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d %d %d",&ah,&am,&as,&bh,&bm,&bs);
        rs=(as+bs)%60;
        rm=((as+bs)/60+am+bm);
        rh=rm/60+ah+bh;
        rm=rm%60;
        printf("%d %d %d\n",rh,rm,rs);
    }
    return 0;
}
