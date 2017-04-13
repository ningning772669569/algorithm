#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#define MAX 100007
using namespace std;
///注意不一定右移到底再左移，只要是右移过程中产生了奇数那么右移一下在左移一下丢掉低位的1以后再不停左移此时产生的数也是可以通过做右移的到的不要忽略
typedef unsigned int un;
struct Vis{
    int times;
    int pay;
};
int N;
struct Vis vis[MAX+1];
/*
int check(int num)
{

    int k=1;
    while(k<num){
        if(k&num)
        return  0;
        k=k<<1;
    }
    return 1;
}*/
void deal (int num)
{

    int lnum=0,rnum=0;
    int tep=num;
    while(tep){
        vis[tep].times++;
        vis[tep].pay=vis[tep].pay+rnum;
        if((tep%2)&&tep>1){
            int step=rnum+2;
            int tep2=tep/2*2;
            while(tep2<MAX){
                vis[tep2].times++;
                vis[tep2].pay+=step;
                step++;
                tep2=tep2<<1;
            }
        }
        tep=tep>>1;
        rnum++;
    }
    tep=num*2;
    while (tep<MAX){



        lnum++;
        vis[tep].times++;
        vis[tep].pay+=lnum;
        tep=tep<<1;
    }
    /*
    if(!check(num)){
        for(int i=1;(1<<i)<MAX;i++){
            vis[1<<i].times++;
            vis[1<<i].pay+=rnum+i-1;
        }
    }*/
}
int main ()
{
    while(scanf("%d",&N)!=EOF){
        int num;
        for(int i=1;i<MAX;i++){
            vis[i].times=0;
            vis[i].pay=0;
        }
        for(int i=1;i<=N;i++){
            scanf("%d",&num);
            deal(num);
        }
        struct Vis re;
        int flag=1;
        for(int i=1;i<MAX;i++){
            if(vis[i].times==N){
                if(flag){
                    re=vis[i];
                    flag=0;
                }
                else{
                    if(re.pay>vis[i].pay)
                        re=vis[i];
                }

            }
        }
        printf("%d\n",re.pay);
    }
}
