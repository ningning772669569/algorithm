#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
const int maxn=10010;
int n,k;
double init[maxn];
double cap[maxn];
vector<int> m[maxn];
void dfs(int v,double water)
{
    int sons=m[v].size();
    if(sons==0){
        init[v]=init[v]+water<cap[v]? init[v]+water:cap[v];
        return;
    }
    double rest=init[v]+water-cap[v];
    if(rest>0){
        init[v]=cap[v];
        for(int i=0;i<sons;i++){
            dfs(m[v][i],rest/sons);
        }
    }
    else{
        init[v]=init[v]+water;
    }
}
int main ()
{
    while(scanf("%d %d",&n,&k)==2){
        for(int i=1;i<=n;i++){
            scanf("%lf lf",&cap[i],&init[i]);
        }
        for(int i=1;i<=k;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            m[from].push_back(to);
        }
        int start,_end;
        double water;
        scanf("%d %lf %d",&start,&water,&_end);
        dfs(start,water);
        printf("%lf\n",init[_end]);
    }

}
