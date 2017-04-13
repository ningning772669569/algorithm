#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "map"
#include "vector"
#include "queue"
using namespace std;
#define INF 199999999
using namespace std;
const int MAXN=1010;
const int MAXM=100010;
typedef  struct {int v,next,val;} edge;
int num[1500];
edge e[MAXM];
int p[MAXN],eid;
int n,m;
int h[MAXN];
int gap[MAXN];
int source,sink;
int two[20];
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
    eid = 0;
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
map<int,int> mm;
int main()
{
    two[0]=1;
    for(int i=1;i<=15;i++)
        two[i]=2*two[i-1];
    while(scanf("%d%d",&n,&m)==2){
        int state;
        mm.clear();
        init();
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=m;j++){
                scanf("%d",&state);
                sum+=state*two[j-1];
            }
            num[sum]++;
        }
        int pnum=0;
        for(int i=1;i<=1024;i++){
            if(num[i]){
                pnum++;
                insert(0,pnum,num[i]);
                mm[i]=pnum;
            }
        }
        for(int i=1;i<=1024;i++){
            if(!num[i]) continue;
            for(int bpos=0;bpos<m;bpos++){
                if(i & (1<<bpos)){
                    insert(mm[i],pnum+bpos+1,num[i]);
                }
            }
        }
        for(int i=1;i<=m;i++){
            int t;
            scanf("%d",&t);
            insert(pnum+i,pnum+m+1,t);
        }
        int re=sap(0,pnum+m+1,pnum+m+2);
        //cout<<re<<endl;
        if(re==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
