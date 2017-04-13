#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"

#include "queue"
#define INF 999999999
using namespace std;
const int MAXE=100000;
const int MAXN=1010;


struct Edge{
    int from, to;
    int next,cap;
}edge[MAXE];
int cnt,n,m;
int src,des;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN], stack[MAXN], top;
int ISAP()
{
    int cur_fLow,max_fLow,u,insert,i;
    memset(dep,0,sizeof(dep));
    memset(gap,0,sizeof(gap));
    memcpy(cur, head, n);
    max_fLow = 0;
    u = src;
    top = 0;
    while(dep[src] < n)
    {
        if(u == des)
        {
            cur_fLow = INF;
            for(i = 0; i < top; ++i)
            {
                if(cur_fLow > edge[stack[i]].cap)
                {
                    insert = i;
                    cur_fLow = edge[stack[i]].cap;
                }
            }
            for(i = 0; i < top; ++i)
            {
                edge[stack[i]].cap -= cur_fLow;
                edge[stack[i]^1].cap += cur_fLow;
            }
            max_fLow += cur_fLow;
            u = edge[ stack[top = insert]].from;
        }
        for(i = cur[u]; i != -1; i = edge[i].next)
            if((edge[i].cap > 0) && (dep[u] == dep[edge[i].to]+1))
                break;
        if(i != -1)
        {
            stack[top++] = i;
            u = edge[i].to;
        }
    else
    {
            if(0 == --gap[dep[u]]) break;
        int minn = n;
            for(i = head[u]; i != -1; i = edge[i].next)
        {
                if(edge[i].cap > 0)
                    minn = (minn > dep[edge[i].to]) ? (cur[u]= i, dep[edge[i].to]) : minn;
        }
            ++gap[dep[u] = minn + 1];
            if(u != src) u = edge[stack[--top]].from;
        }
    }
    return max_fLow;
}
void addedge(int u,int v,int f)
{
    edge[cnt].next = head[u];
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].cap = f;
    head[u] = cnt++;
    edge[cnt].next = head[v];
    edge[cnt].from = v;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    head[v] = cnt++;
}

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while (T--)
    {
        int ans=0;
        //init();

        scanf("%d%d",&n,&m);
        cnt=0;des=n+500+1;src=0;
        for(int i=1;i<=n;i++){
            int p,s,e;
            scanf("%d%d%d",&p,&s,&e);
            ans+=p;
            addedge(0,i,p);
            for(int j=s;j<=e;j++){
                addedge(i,j+n,1);
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=500;i++)
            addedge(i+n,n+500+1,m);
        bool flag = false;
        //cout<<sap(0, n+500+1)<<endl;
        if (ans == ISAP())
        {
            flag = true;
        }
        printf("Case %d: %s\n\n", ++cas, flag ? "Yes" : "No");
    }
    return 0;
}
