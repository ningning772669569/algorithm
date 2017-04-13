#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "utility"
#include "vector"
#include "queue"
using namespace std;
typedef pair<int,int> pii;
const int maxn=100010;
int n,m;
vector<int> tree[maxn];
int vis[maxn];
pii bfs(int root)
{
    memset(vis,0,sizeof(vis));
    queue<pii> q;
    q.push(make_pair(root,0));
    vis[root]=1;
    int rev,red;
    int v,d;
    while(!q.empty()){
        pii x=q.front();
        q.pop();
        v=x.first;
        d=x.second;
        if(vis[v])
            continue;
        rev=v;
        red=d;
        vis[v]=1;
        for(int i=0;i<tree[v].size();i++){
            int u=tree[v][i];
            if(vis[u])
                continue;
            q.push(make_pair(u,d+1));
        }
    }
    return make_pair(rev,red);

}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            tree[i].clear();
        for(int i=1;i<=n-1;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        pii tep=bfs(1);
        pii re=bfs(tep.first);

        for(int i=1;i<=m;i++){
            int k;
            scanf("%d",&k);
            if(k<re.second+1)
                printf("%d\n",k-1);
            else{
                printf("%d\n",2*(k-re.second-1)+re.second);
            }
        }

    }
    return 0;
}
