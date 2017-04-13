#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "set"
#include "utility"
using namespace std;
typedef pair<int,int> pi;
struct point{
    int x,y;
}p[1006];
int n;
set<pi> s;
int cmp(const struct point &p,const struct point &q)
{
    if(p.x!=q.x){
        return p.x<q.x;

    }
    else{
        return p.y<q.y;
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p[i].x,&p[i].y);
        }
        if(n<4){
            printf("0\n");
            continue;
        }
        s.clear();
        int num=0;
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++){
            s.insert(make_pair(p[i].x,p[i].y));
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i==j)
                    continue;
                if(abs(p[i].x-p[j].x)!=abs(p[i].y-p[j].y))
                    continue;
                pi tep=make_pair(p[i].x,p[j].y);
                if(!s.count(tep))
                    continue;
                tep=make_pair(p[j].x,p[i].y);
                if(!s.count(tep))
                    continue;
                num++;
            }
        }
        printf("%d\n",num/2);
    }
}
