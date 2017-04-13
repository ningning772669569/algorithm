#include "cstdio"
#include "algorithm"
#include "cstring"
#include "iostream"
#define MAX_H 21
#define MAX_W 21
#include "queue"

using namespace std;
int num;
int H,W;
char _map[MAX_H][MAX_W];
bool vis[MAX_H][MAX_W];
void _find (int x,int y)
{
    if(_map[x][y]=='.'||_map[x][y]=='@'){
        if(!vis[x][y]){
            num++;
            vis[x][y]=1;
            if(x>1)
                _find(x-1,y);
            if(y>1)
                _find(x,y-1);
            if(x<H)
                _find(x+1,y);
            if(y<W)
                _find(x,y+1);

        }
    }

}

int main ()
{

    while(1){
        int start_i=0,start_j=0;
        scanf("%d %d",&W,&H);
        getchar();
        if(H==0&&W==0)
            break;
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                scanf("%c",&_map[i][j]);
                if(_map[i][j]=='@'){
                    start_i=i;
                    start_j=j;
                }
            }
            getchar();
        }
        memset(vis,0,sizeof(vis));
        num=0;
        _find(start_i,start_j);
        printf("%d\n",num);
    }
    return 0;
}

