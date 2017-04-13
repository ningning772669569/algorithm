#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
int maxnum,mintime;
char win[30];
int N;
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        scanf("%s %d %d",win,&maxnum,&mintime);
        for(int i=2;i<=N;i++){
            char tepname[30];
            int tepnum,teptime;
            scanf("%s %d %d",tepname,&tepnum,&teptime);
            if(tepnum>maxnum){
                maxnum=tepnum;
                strcpy(win,tepname);
                mintime=teptime;
            }
            else if(tepnum==maxnum){
                if(teptime<mintime){
                    maxnum=tepnum;
                    strcpy(win,tepname);
                    mintime=teptime;
                }
            }
        }
        printf("%s\n",win);
    }
    return 0;

}
