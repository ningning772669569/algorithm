///是一个有向图……双层建图
#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "queue"
#include "utility"
#define MAX 10009
#define INF 100000001
using namespace std;


typedef pair <long long,int>pi;
int n,m;
vector <pi> G[MAX];
bool visited[MAX];
priority_queue<pi,vector<pi>,greater<pi> > q;
int fa[MAX];
int d[MAX];
int d2[MAX];

int main ()
{
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int a,b,l;

        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        for(int i=1;i<=m;i++){
            scanf("%d %d %ld",&a,&b,&l);
            G[a].push_back(make_pair(b,l*10));

        }
        for(int i=1;i<=n;i++){
            d2[i]=d[i]=(i==1? 0 :INF);
        }
        memset(visited,0,sizeof(visited));

        q.push(make_pair(d[1],1));
        while(!q.empty()){
            pi u=q.top();
            q.pop();
            int x=u.second;
            if(visited[x]){
                continue;
            }
            visited[x]=true;
            for(int e=0;e<G[x].size();e++){
                pi v=G[x][e];

                int now =v.first;
                int length =v.second;

                if(d[now]>d[x]+length){
                    d[now]=d[x]+length;
                    q.push(make_pair(d[now],now));

                }
                d2[now]=min(d2[now],min(d[x]+length/2,d2[x]+length));



            }
        }


        if(d2[n]%10==0){
            printf("%d\n",d2[n]/10);

        }
        else {
            printf("%d.%d\n",d2[n]/10,d2[n]%10);
        }
    }
    return 0;
}
