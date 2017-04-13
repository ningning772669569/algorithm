#include "algorithm"
#include "cstdio"
#include "string"
using namespace std;
#define MAXLINE 100
#define MAXSTATE 100
int dp[MAXLINE][MAXSTATE][MAXSTATE];
int m,n;        ///代表读入的地图的行数和列数
int map[MAXLINE];     ///将地图的信息压缩存储
int state_num;
int num[MAXSTATE];


void init();
int get_num(int);

int main ()
{
    int i,j;    ///循环变量
    char state;
    scanf ("%d %d",&m,&n);
    ///制作map
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            state=getchar();
            if(state=='P')
                map[i]=map[i]|(1<<j);   ///对1进行移动然后在进行或 不是或之后在进行移动

            else{
                map[i]=map[i]&(0<<j);
            }
        }
    }
    init();

}
void init ()
{
    int i,j;
    for(i=0;i<(1<<n);i++){
        if(i&(i<<1))
            continue;
        if(i&(i<<2))
            continue;
        state_num++;
        num[state_num]=get_num(i);
    }
}
int get_num(int num)
{

    int i=0;
    while(num){
        if(num&1)
            i++;
        num=num>>1;
    }
    return i;
}
