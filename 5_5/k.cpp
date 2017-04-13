#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
int n,m;
int block[105][105];
int vis[105][105];
int diri[]={0,0,0,1,-1};
int dirj[]={0,1,-1,0,0};
char path[501];
int sum;
int posi,posj;
int dir;
int len;
int getdir(char c)
{
    if(dir==1){
        if(c=='R')
            return 3;
        else
            return 4;
    }
    else if(dir==2){
        if(c=='R')
            return 4;
        else
            return 3;
    }
    else if(dir==3){
        if(c=='R')
            return 2;
        else
            return 1;
    }
    else{
        if(c=='R')
            return 1;
        else
            return 2;
    }
}
void update()
{
    if(dir==1){
        if(posi>0){
            if(vis[posi][posj+1]){
                sum=sum+block[posi][posj+1]/2;
            }
            else{
                sum=sum+block[posi][posj+1];
                vis[posi][posj+1]=1;
            }
        }
        if(posi<n){
            if(vis[posi+1][posj+1]){
                sum+=block[posi+1][posj+1]/2;
            }
            else{
                sum+=block[posi+1][posj+1];
                vis[posi+1][posj+1]=1;
            }
        }
    }
    else if(dir==2){
        if(posi>0){
            if(vis[posi][posj]){
                sum=sum+block[posi][posj]/2;
            }
            else{
                sum=sum+block[posi][posj];
                vis[posi][posj]=1;
            }
        }
        if(posi<n){
            if(vis[posi+1][posj]){
                sum+=block[posi+1][posj]/2;
            }
            else{
                sum+=block[posi+1][posj];
                vis[posi+1][posj]=1;
            }
        }

    }
    else if(dir==3){
        if(posj>0){
            if(vis[posi+1][posj]){
                sum+=block[posi+1][posj]/2;
            }
            else {
                sum+=block[posi+1][posj];
                vis[posi+1][posj]=1;
            }
        }
        if(posj<m){
            if(vis[posi+1][posj+1])
                sum+=block[posi+1][posj+1]/2;
            else{
                sum+=block[posi+1][posj+1];
                vis[posi+1][posj+1]=1;
            }
        }
    }
    else{
        if(posj>0){
            if(vis[posi][posj]){
                sum+=block[posi][posj]/2;
            }
            else{
                sum+=block[posi][posj];
                vis[posi][posj]=1;
            }
        }
        if(posj<m){
            if(vis[posi][posj+1]){
                sum+=block[posi][posj+1]/2;
            }
            else{
                sum+=block[posi][posj+1];
                vis[posi][posj+1]=1;
            }
        }
    }
}
void Move(int step)
{
    if(step==len)
        return;
    char c=path[step];
    if(c=='R'||c=='L'){
        dir=getdir(c);
    }
    else{
        update();
        posi=posi+diri[dir];
        posj=posj+dirj[dir];

    }
    Move(step+1);
}
int main ()
{
    while(scanf("%d %d",&n,&m)==2){
        memset(vis,0,sizeof(vis));
        memset(block,0,sizeof(block));
        sum=0;
        posi=0;posj=0;dir=1;
        for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++){
                char c;
                c=getchar();
                block[i][j]=c-'0';
            }
        }
        scanf("%s",path);
        len=strlen(path);
        Move(0);
        printf("%d\n",sum);

    }
}

