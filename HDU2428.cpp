#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "set"
#include "utility"
using namespace std;
const int maxn=1010;
typedef pair<int,int> pii;
int N;
pii star[maxn];
set<pii> S;
int cmp(const pii &p,const pii &q)
{
    if(p.first!=q.first)
        return p.first<q.first;
    else{
        return p.second<q.second;
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        S.clear();
        for(int i=1;i<=N;i++){
            scanf("%d%d",&star[i].first,&star[i].second);
            S.insert(star[i]);
        }
        sort(star+1,star+1+N,cmp);
        if(N<=3)
        {
            printf("0\n"); continue;
        }
        int re=0;
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                pii t1,t2;
                if(star[i].first==star[j].first)    continue;
                if(star[i].second==star[j].second)  continue;
                if(abs(star[i].first-star[j].first)!=abs(star[i].second-star[j].second)) continue;
                t1.first=star[i].first;t1.second=star[j].second;
                t2.first=star[j].first;t2.second=star[i].second;
                if(S.count(t1) && S.count(t2))
                    re++;
            }
        }
        printf("%d\n",re/2);
    }
}
