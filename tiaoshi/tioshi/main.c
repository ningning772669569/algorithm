#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;
typedef long long LL;
const int MAX=1000000;
struct node {
    int num[9];
};

int step[MAX];
node state[MAX];
node start;
node target;
int vis[400000];
int fac[10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int decode(const node & p)
{
    int code=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)
            if(p.num[j]<p.num[i])
                cnt++;
        code += cnt*fac[9-i];
    }
    return code;
}

int bfs(node & start,node & target)
{
    memset(vis,0,sizeof(vis));
    int front=1,rear=2;
    memcpy(&state[front],&start,sizeof(node));
    step[front]=0;
    int t=decode(start);
    vis[t]=1;
    while(front<rear){
        node & tep=state[front];
        front++;
        cout<<1<<endl;
        if(memcmp(&tep,&target,sizeof(node))==0){
            return step[front];
        }
        cout<<2<<endl;
        int pos;
        for(int i=0;i<=9;i++){
            if(tep.num[i]==0){
                pos=i;
                break;
            }
        }
        int x,y;
        x=pos/3;
        y=pos%3;
        for(int i=0;i<4;i++){
            node newnode;
            memcpy(&newnode,&tep,sizeof(node));
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<=2&&ny>=0&&ny<=2){
                int teppos=nx*3+ny;
                swap(newnode.num[pos],newnode.num[teppos]);
                int tepcode=decode(newnode);
                if(vis[tepcode])
                    continue;
                else {
                    memcpy(&state[rear],&newnode,sizeof(node));
                    step[rear]=step[front]+1;
                    rear++;
                }
            }
        }
    }
    return -1;
}
void init()
{

    fac[1]=1;
    for(int i=2;i<=9;i++){
        fac[i]=fac[i-1]*i;
    }
}

int main ()
{
    init();
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){

        for(int i=0;i<9;i++){
            scanf("%d",&start.num[i]);
        }

        for(int i=0;i<=9;i++){
            scanf("%d",&target.num[i]);
        }
        int re=bfs(start,target);
        printf("Case #%d: %d\n",t,re);
    }
    return 0;
}
