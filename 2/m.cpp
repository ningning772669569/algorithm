#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#define INF 100000
#define  MAX 22
using namespace std;
int dp1[MAX][MAX];
int dp2[MAX][MAX];
int _map[MAX][MAX];
int vis[MAX][MAX];
struct position{
int i,j;
int state;
};
vector<struct position> pos;
int main ()
{
    int M,N;

    while(scanf("%d %d",&M,&N)==2){
    getchar();
    int start_i,start_j,fin_i,fin_j;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            scanf("%c",&_map[i][j]);
            if(_map[i][j]=='S'){
                start_i=i;
                start_j=j;
            }
            if(_map[i][j]=='T'){
                fin_i=i;
                fin_j=j;
            }
            if(_map[i][j]=='-'){
                struct position _tep;
                _tep.i=i;
                _tep.j=j;
                _tep.state=0;
                pos.push_back(_tep);
            }
            if(_map[i][j]=='|'){
                struct position _tep;
                _tep.i=i;
                _tep.j=j;
                _tep.state=1;
                pos.push_back(_tep);
            }
        }
        getchar();
    }
    queue<int> qi,qj,dis;

    qi.push(start_i);
    qj.push(start_j);
    dis.push(0);

    memset(vis,0,sizeof(vis));
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            dp1[i][j]=dp2[i][j]=INF;
        }

    }
    while(!qi.empty()){
        int tepi=qi.front();
        int tepj=qj.front();

        int tepdis;
        tepdis=dis.front();
        qi.pop();
        qj.pop();
        dis.pop();
        if(_map[tepi][tepj]=='*')   continue;
        if(_map[tepi][tepj]=='-'||_map[tepi][tepj]=='|')    continue;
        if(vis[tepi][tepj]) continue;
        dp1[tepi][tepj]=tepdis;
        vis[tepi][tepj]=1;
        if(tepi>1)  {qi.push(tepi-1);qj.push(tepj);dis.push(tepdis+1);}
        if(tepj>1)  {qi.push(tepi);qj.push(tepj-1);dis.push(tepdis+1);}
        if(tepi<M)  {qi.push(tepi+1);qj.push(tepj);dis.push(tepdis+1);}
        if(tepj<N)  {qi.push(tepi);qj.push(tepj+1);dis.push(tepdis+1);}


    }
    memset(vis,0,sizeof(vis));

    qi.push(fin_i);
    qj.push(fin_j);
    dis.push(0);

    while(!qi.empty()){
        int tepi=qi.front();
        int tepj=qj.front();
        int tepdis;
        tepdis=dis.front();
        qi.pop();
        qj.pop();
        dis.pop();

        if(_map[tepi][tepj]=='*')   continue;
        if(_map[tepi][tepj]=='-'||_map[tepi][tepj]=='|')    continue;
        if(vis[tepi][tepj]) continue;
        dp2[tepi][tepj]=tepdis;
        vis[tepi][tepj]=1;
        if(tepi>1)  {qi.push(tepi-1);qj.push(tepj);dis.push(tepdis+1);}
        if(tepj>1)  {qi.push(tepi);qj.push(tepj-1);dis.push(tepdis+1);}
        if(tepi<M)  {qi.push(tepi+1);qj.push(tepj);dis.push(tepdis+1);}
        if(tepj<N)  {qi.push(tepi);qj.push(tepj+1);dis.push(tepdis+1);}


    }
    int Min=dp1[fin_i][fin_j];
    for(int i=0;i<pos.size();i++){
        int bposi=pos[i].i;
        int bposj=pos[i].j;
        if(bposi>1&&bposi<M&&dp1[bposi-1][bposj]!=INF&&dp2[bposi+1][bposj]!=INF){
            if((dp1[bposi-1][bposj]%2&&pos[i].state)||((dp1[bposi-1][bposj]%2==0)&&(pos[i].state==0))){
                Min=min(Min,dp1[bposi-1][bposj]+2+dp2[bposi+1][bposj]);
            }
            else {
                Min=min(Min,dp1[bposi-1][bposj]+1+dp2[bposi+1][bposj]);
            }
        }
        if(bposi>1&&bposi<M&&dp1[bposi+1][bposj]!=INF&&dp2[bposi-1][bposj]!=INF){
            if((dp1[bposi+1][bposj]%2&&pos[i].state)||((dp1[bposi+1][bposj]%2==0)&&(pos[i].state==0))){
                Min=min(Min,dp1[bposi+1][bposj]+2+dp2[bposi-1][bposj]);
            }
            else {
                Min=min(Min,dp1[bposi+1][bposj]+1+dp2[bposi-1][bposj]);
            }
        }
        if(bposj>1&&bposj<N&&dp1[bposi][bposj-1]!=INF&&dp2[bposi][bposj+1]!=INF){
            if((dp1[bposi][bposj-1]%2&&pos[i].state)||((dp1[bposi][bposj-1]%2==0)&&(pos[i].state==0))){
                Min=min(Min,dp1[bposi][bposj-1]+1+dp2[bposi][bposj+1]);
            }
            else {
                Min=min(Min,dp1[bposi][bposj-1]+2+dp2[bposi][bposj+1]);
            }
        }
        if(bposj>1&&bposj<N&&dp1[bposi][bposj+1]!=INF&&dp2[bposi][bposj-1]!=INF){
            if((dp1[bposi][bposj+1]%2&&pos[i].state)||((dp1[bposi][bposj+1]%2==0)&&(pos[i].state==0))){
                Min=min(Min,dp1[bposi][bposj+1]+1+dp2[bposi][bposj-1]);
            }
            else {
                Min=min(Min,dp1[bposi][bposj+1]+2+dp2[bposi][bposj-1]);
            }
        }
    }
    printf("%d\n",Min);
    }
    return 0;
}
