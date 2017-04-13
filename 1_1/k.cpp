#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n;
int Max;
struct Times{
    int time;
    int l,r;
}times[1000006];
void init()
{
    for(int i=1;i<1000001;i++){
        times[i].time=0;
        times[i].l=n;
        times[i].r=0;
    }
}
int cmp(const struct Times &p,const struct Times &q)
{
    if(p.time!=q.time)
        return q.time<p.time;
    else{
        return (q.r-q.l)>(p.r-p.l);
    }
}
int main()
{
   while(scanf("%d",&n)!=EOF){
         Max=0;
        init();
        int num;
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            if(num>Max)
                Max=num;
            times[num].time++;
            if(i<times[num].l)
                times[num].l=i;
            if(i>times[num].r)
                times[num].r=i;
        }
        sort(times+1,times+Max+1,cmp);
        printf("%d %d\n",times[1].l,times[1].r);
   }
   return 0;
}
