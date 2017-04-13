#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
const int maxn=110;

int pre[maxn];
int low[maxn];
bool iscut[maxn];
int n;
int num;
int dfsid;
vector<int> m[maxn];
int dfs(int v,int fa)
{
    int lowu;
    lowu=pre[v]=++dfsid;
    int childs=0;
    for(vector<int>::size_type i=0;i<m[v].size();i++){

        int son=m[v][i];
        if(!pre[son]){

            childs++;
            int teplow=dfs(son,v);
            lowu=min(lowu,teplow);
            if(teplow>=pre[v])
                iscut[v]=true;

        }
        else if(pre[son]<pre[v]){
            if(v!=fa)
            lowu=min(lowu,pre[son]);
        }
    }
    low[v]=lowu;

    if(fa<0&&childs==1)
        iscut[v]=false;

    return lowu;

}
int main ()
{
    while(1){
        memset(pre,0,sizeof(pre));
        memset(iscut,0,sizeof(iscut));
        for(int i=0;i<maxn;i++){
            m[i].clear();
        }
        scanf("%d",&n);
        if(!n)
            break;
        for(int i=1;i<=n;i++){
            int place;

            scanf("%d",&place);
            if(!place)
                break;
            int from;
            char c=getchar();
            while(c!='\n'){
            scanf("%d",&from);
            c=getchar();
            m[place].push_back(from);
            m[from].push_back(place);
            //cout<<from<<endl;
            }


            //printf("%d",m[place].size());


        }
        num=0;
        dfsid=0;
        dfs(1,-1);
        for(int i=1;i<=n;i++)
            if(iscut[i])
                num++;
        printf("%d\n",num);
    }
    return 0;
}
