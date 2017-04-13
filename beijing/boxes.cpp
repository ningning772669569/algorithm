#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "map"
using namespace std;
typedef long long LL;
struct node{
    int pos[9];
    node(){memset(pos,0,sizeof(pos));}
};
int vis[10000007];
int fac][10]
int decode(node & p)
{
    int code=0;
    for(int i=1;i<=8;i++){
        code = code * 10+ p.pos[i];
    }
}
void bfs(int n)
{
    node start;
    for(int i=1;i<=n;i++)
        start.pos[i]=i;
    queue<node> q;
    q.push(start);
    while(!q.empty()){
        node tep=q.front();
        q.pop();

    }
}
void init()
{
    fac[1]=1;
    for(int i=2;i<=8;i++){
        fac[i]=fac[i-1]*i;
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=8;i++){
        bfs(i);
    }
}
int main ()
{


}
