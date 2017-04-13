#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "queue"
using namespace std;
const int maxn=20010;
int N,K;
int f[maxn];
int p[maxn];
int partsnum;
vector<int> tree[maxn];
void dfs(int u,int fa)
{
    f[u]=fa;
    for(int i=0;i<tree[u].size();i++){
        dfs(tree[u][i],u);
    }
}

int findset(int x)
{
    //cout<<x<<endl;
    return f[x]!=x ? findset(f[x]) : x;
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&N,&K);
        for(int i=0;i<maxn;i++)
            tree[i].clear();
        for(int i=1;i<=N;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=N;i++){
            tree[p[i]].push_back(i);
        }

        for(int i=0;i<tree[0].size();i++){
            dfs(tree[0][i],tree[0][i]);
        }
        printf("Case #%d:\n",t);
        for(int i=1;i<=K;i++){
            char c;
            getchar();
            scanf("%c",&c);
            //cout<<c<<endl;
            if(c=='C'){
                int num;
                scanf("%d",&num);
                f[num]=num;
            }
            else{
                //cout<<"^^^^^^^^^^"<<endl;

                int f1,f2;
                //scanf("%d %d",&u,&v);
                int a,b;
                cin>>a>>b;
                //cout<<"u   " <<u<<"  "<<v<<endl;
                f1=findset(b);
                f2=findset(a);
                //cout<<f1<<endl;
                if(f1==f2)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }

}
