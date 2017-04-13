#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "queue"
using namespace std;
bool vis[2500];
int Map[8][8];
int M,N;
int desi,desj;
int pi,pj;
int bi,bj;
struct state{
    int pi,pj,bi,bj;
    int steps;
    state():steps(0){}
};
queue <struct state> q;
bool check(const struct state & p)
{
    int num;
    num=p.pi*7+p.pj;
    num=num*49+p.bi*7+p.bj;
    if(vis[num])
        return true;
    return false;
}
void update (const struct state& p)
{
    int num;
    num=p.pi*7+p.pj;
    num=num*49+p.bi*7+p.bj;
    vis[num]=true;

}
void BFS()
{
    struct state start;
    int flag=0;
    start.pi=pi;start.pj=pj;start.bi=bi;start.bj=bj;start.steps=0;
    q.push(start);
    while(!q.empty()){
        struct state u=q.front();
        q.pop();
        if(check(u))
            continue;
        update(u);
        if(u.bi==desi&&u.bj==desj){
            printf("%d\n",u.steps);
            flag=1;
            break;
        }
        if((abs(u.pi-u.bi)==1&&abs(u.pj-u.bj)==0)||(abs(u.pi-u.bi)==0&&abs(u.pj-u.bj)==1)){
                int direi,direj;
                direi=u.pi-u.bi;
                direj=u.pj-u.bj;
                if(direi!=0){
                    if(u.bi-direi>0&&u.bi-direi<=M&&(!Map[u.bi-direi][u.bj])){
                        struct state v(u);
                        v.bi=v.bi-direi;
                        v.pi=v.pi-direi;
                        v.steps++;
                        q.push(v);
                    }

                }
                else{
                    if(u.bj-direj>0&&u.bj+direj<=N&&!Map[u.bi][u.bj-direj]){
                        struct state v(u);
                        v.bj=v.bj-direj;
                        v.pj=v.pj-direj;
                        v.steps++;
                        q.push(v);
                    }
                }
        }

            if(u.pi>1&&!Map[u.pi-1][u.pj]&&!((u.pi-1)==u.bi&&u.pj==u.bj)){
                struct state v(u);
                v.pi--;
                q.push(v);
            }
            if(u.pi<M&&!Map[u.pi+1][u.pj]&&!((u.pi+1)==u.bi&&u.pj==u.bj)){
                struct state v(u);
                v.pi++;
                q.push(v);
            }
            if(u.pj>1&&!Map[u.pi][u.pj-1]&&!(u.pi==u.bi&&(u.pj-1)==u.bj)){
                struct state v(u);
                v.pj--;
                q.push(v);
            }
            if(u.pj<N&&!Map[u.pi][u.pj+1]&&!(u.pi==u.bi&&(u.pj+1)==u.bj)){
                struct state v(u);
                v.pj++;
                q.push(v);
            }


    }
    if(!flag)
        printf("-1\n");
}
int main ()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        while(!q.empty()){
            q.pop();
        }
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&M,&N);
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                int tep;
                scanf("%d",&tep);
                if(tep==0)
                    Map[i][j]=0;
                if(tep==1)
                    Map[i][j]=1;
                if(tep==3){
                    Map[i][j]=0;
                    desi=i;
                    desj=j;
                }
                if(tep==2){
                    Map[i][j]=0;
                    bi=i;bj=j;
                }
                if(tep==4){
                    Map[i][j]=0;
                    pi=i;pj=j;
                }
            }
        }
        BFS();

    }
    return 0;
}
