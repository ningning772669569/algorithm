#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
using namespace std;
const int maxn=100010;
vector<int> pri[maxn];
vector<int> ty[maxn];
vector<int> G[maxn];
int ispri[maxn];
int ch[maxn][65];
int num[maxn];
int val[maxn];
int re[maxn];
int N;
void init ()
{
    for(int i=1;i<maxn;i++) ispri[i]=1;
    ispri[2]=1;
    for(int i=2;i<maxn;i++){
        if(ispri[i]){
            for(int j=i;j<maxn;j+=i)
                ispri[j]=0,pri[j].push_back(i);
        }
    }
    vector<int> x;
    for(int i=2; i<maxn; i++){
        x.clear();
        for(int j=0;j<pri[i].size();j++)
            x.push_back(pri[i][j]);
        pri[i].clear();
        int n=x.size();
        //cout<<n<<endl;
        for(int j = 1; j < (1<<n); j++){
            int y=1;
            int f=0;
            for(int k=0;k<n;k++){
                if(j & (1<<k)){
                    y = y * x[k];
                    f++;
                }
            }
            pri[i].push_back(y);
            if(f&1) ty[i].push_back(-1);
            else ty[i].push_back(1);
        }

    }


}
int dfs(int u,int fa)
{
    int son=0;
    int va=val[u];
    for(int i=0;i<pri[va].size();i++){
        ch[u][i]=num[pri[va][i]];
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        son+=dfs(v,u);
    }
    re[u]=son;
    for(int i=0;i<pri[va].size();i++){
        re[u]+=num[pri[va][i]]-ch[u][i];
    }
    for(int i=0;i<pri[va].size();i++){
        num[pri[va][i]]+=ty[va][i];
    }
    if(va==1)
        re[u]++;
    return son+1;
}
int main ()
{
    int caseid=0;
    init();
    while(scanf("%d",&N)!=EOF){
        for(int i=0;i<=N;i++)   G[i].clear();
        for(int i=1;i<N;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(num,0,sizeof(num));
        for(int i=1;i<=N;i++)
            scanf("%d",&val[i]);
        dfs(1,-1);
        printf("Case #%d:",++caseid);
        for(int i=1;i<=N;i++)
            printf(" %d",re[i]);
        printf("\n");
    }

}
