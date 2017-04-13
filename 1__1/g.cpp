#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
struct Event{
    int from,to;
};
struct Event event[21];
int num;
int maxnum;
int cmp(const struct Event&p,const struct Event& q)
{
    return p.from<q.from;
}
void DFS(int cur,int a)
{
    if(a>maxnum)
        maxnum=a;
    for(int i=cur+1;i<num;i++){
        if(event[i].from>=event[cur].to)
            DFS(i,a+1);
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int from,to;
        num=0;
        maxnum=0;
        while(scanf("%d %d",&from,&to)==2){
            if(from==0&&to==0){
                break;
            }
            event[num].from=from;event[num].to=to;
            num++;
        }
        sort(event,event+num,cmp);
        for(int i=0;i<num;i++){
            DFS(i,1);
        }
        //printf("%d\n",event[0].from);
        printf("%d\n",maxnum);
    }
}
