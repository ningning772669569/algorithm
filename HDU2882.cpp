#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "vector"
#define INF 199999999
using namespace std;
const int maxn=220;
const int MAXN=1010;
const int MAXM=100010;
typedef  struct {int v,next,val;} edge;

edge e[MAXM];
int ss[maxn];
int tt[maxn];
int ee[maxn];
int nn[maxn];
int p[MAXN],eid, ans;
int n,m;
int h[MAXN];
int gap[MAXN];
int source,sink;
int num[MAXN];
inline void insert(int from,int to,int val)
{
    e[eid].v=to;
    e[eid].val=val;
    e[eid].next=p[from];
    p[from]=eid++;

    e[eid].v=from;
    e[eid].val=0;
    e[eid].next=p[to];
    p[to]=eid++;
}

void init()
{
    memset(p, -1, sizeof(p));
    ans = eid = 0;
}

inline int dfs(int pos,int cost, int cnt)
{
    if (pos==sink)
    {
        return cost;
    }

    int j,minh=cnt-1,lv=cost,d;

    for (j=p[pos];j!=-1;j=e[j].next)
    {
        int v=e[j].v,val=e[j].val;
        if(val>0)
        {
            if (h[v]+1==h[pos])
            {
                if (lv<e[j].val) d=lv;
                else d=e[j].val;

                d=dfs(v,d,cnt);
                e[j].val-=d;
                e[j^1].val+=d;
                lv-=d;
                if (h[source]>=cnt) return cost-lv;
                if (lv==0) break;
            }

            if (h[v]<minh)    minh=h[v];
        }
    }

    if (lv==cost)
    {
        --gap[h[pos]];
        if (gap[h[pos]]==0) h[source]=cnt;
        h[pos]=minh+1;
        ++gap[h[pos]];
    }

    return cost-lv;

}

int sap(int st,int ed, int cnt)
{
    source=st;
    sink=ed;
    int ret=0;
    memset(gap,0,sizeof(gap));
    memset(h,0,sizeof(h));

    gap[st]=cnt;

    while (h[st]<cnt)
    {
        ret+=dfs(st,0x3f3f3f3f, cnt);
    }

    return ret;
}

int main ()
{
    while(scanf("%d%d",&n,&m)==2){
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&ss[i],&nn[i],&ee[i],&tt[i]);
            sum+=nn[i]*tt[i];
        }
        init();
        int size=0;
        for(int i=1;i<=n;i++)
        {
            insert(0,i,nn[i]*tt[i]);
            num[++size]=ss[i];
            num[++size]=ee[i];
        }
        sort(num+1,num+size+1);
        size=unique(num+1,num+1+size)-num;
        for(int i=1;i<size-1;i++){
            insert(n+i,n+size-1,(num[i+1]-num[i])*m);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<size-1;j++){
                if(ss[i]<=num[j] && ee[i]>=num[j]+1)
                    insert(i,j+n,INF);

            }
        }
        int re=sap(0,n+size-1,n+size);
        if(re==sum)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
