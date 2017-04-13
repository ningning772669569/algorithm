#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
vector <int> n[10010];
int g[10010],f[10010],ns[10010],xx;//xx已经遍历的节点个数
long long sum,sum2;
void DFS(int z){//深搜
    xx++;
    f[z]=1;
    sum2+=g[z];
    for(int i=0;i<n[z].size();i++)
    if(!f[n[z][i]]) DFS(n[z][i]);
}
int main()
{
    int T,p,m,x,y;
    scanf("%d",&T);
    while(T--){
        sum = xx = 0;
        memset(f,0,sizeof(f));//初始化
        memset(g,0,sizeof(g));//初始化
        memset(ns,0,sizeof(ns));//初始化
        for(int i=0;i<10010;i++)
            n[i].clear();//初始化
        scanf("%d%d",&p,&m);
        for(int i=1;i<=p;i++)
            scanf("%d",&g[i]);
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            n[x].push_back(y);
            n[y].push_back(x);
            ns[x]++;
            ns[y]++;
        }
        bool key=true;
        while(key){
            key=false;
            for(int i=1;i<=p;i++)
                if(ns[i]==1||ns[i]==0){
                    key=true;
                    f[i]=1;//当作已经遍历过
                    for(int j=0;j<n[i].size();j++)
                        ns[n[i][j]]--;
                    ns[i]=-1;
                }
        }
        for(int i=1;i<=p;i++){
            if(!f[i]){
                sum2=xx=0;
                DFS(i);
                if(xx%2==1)//连通奇数个
                    sum+=sum2;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
