#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "queue"
#include "utility"
#define MAX 110
#define INF 10000001
using namespace std;
struct edge{
    int a,b,w;
};
struct edge bian[MAX];
int n,m;
int p[MAX];
int _find(int x)
{
    return p[x]==x? x: p[x]=_find(p[x]);
}
int cmp(const struct edge & p1,const struct edge & p2)
{
    return p1.w<p2.w;
}
int cost;
int main ()
{
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        cost=0;
        int a,b,c;
        scanf("%d %d",&n,&m);
        if(m==0&&n!=1){
            cout << "I'm not sure.\n";
            continue;

        }
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            bian[i].a=a;
            bian[i].b=b;
            bian[i].w=c;
        }
        sort(bian,bian+n,cmp);

        for(int i=1;i<=m;i++){
            p[i]=i;
        }
        for(int i=0;i<n;i++){
            int x=_find(bian[i].a);
            int y=_find(bian[i].b);
            if(x!=y){
               cost+=bian[i].w;
               p[x]=y;
            }
        }
        int flag=1;
        ///检查是否无法构成连通图
        for(int i=1;i<=m;i++){
            if(_find(i)!=_find(1)){
                cout << "I'm not sure.\n";
                flag=0;
                break;

            }
        }
        if(flag)
        printf("%d\n",cost);

    }

}
