#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"
using namespace std;
int n;
int sum;
deque<int> road;
struct node{
    int num;
    int ok;
};
deque<struct node>  g[100005];
int have[100005];
int vis[100005];
vector<int> re;
void push_up()
{
    deque<int>::iterator iter=road.end();
    iter--;
    while(iter!=road.begin()){
        if(!have[*iter])
            break;
        else{
            have[*iter]=0;
            iter--;
        }
    }
}
void dfs(int v)
{

    int sons=g[v].size();
    if(sons==1){
        if(g[v][0].ok==2){
            sum++;
            push_up();
            re.push_back(v);
        }
        return ;
    }
    int father=0;
    for(int i=0;i<sons;i++){
        int tep=g[v][i].num;
        if(vis[tep]){
            father=tep;
            if(g[v][i].ok==2){
                have[v]=1;
            }
        }

    }

    if(father&&have[father]){
        have[v]=1;
    }
    for(int i=0;i<sons;i++){
        if(!vis[g[v][i].num]){
            road.push_back(g[v][i].num);
            dfs(g[v][i].num);
            road.pop_back();
        }
    }
    if(have[v]){
        sum++;
        push_up();
        re.push_back(v);
    }

}
int main ()
{
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        memset(have,0,sizeof(have));
        while(!road.empty())
            road.pop_back();
        sum=0;
        re.clear();
        for(int i=1;i<n;i++){
            int left,right,ok;
            scanf("%d %d %d",&left,&right,&ok);
            struct node tep;
            tep.num=left;
            tep.ok=ok;
            g[right].push_back(tep);
            tep.num=right;
            g[left].push_back(tep);
        }
        road.push_back(1);
        dfs(1);
        printf("%d\n",sum);
        for(int i=0;i<re.size();i++){
            printf("%d",re[i]);
            if(i<re.size()-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}


