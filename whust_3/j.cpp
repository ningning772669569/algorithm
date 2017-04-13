#include "iostream"
#include "cstdio"
#include "cstring"
#include "set"
#include "algorithm"
using namespace std;
int n;
int re;
typedef long long LL;
struct card{
    LL h,w;
};
multiset<int> store;
struct card alice[100005];
struct card bob [100005];
int cmp(const struct card &p,const struct card & q)
{
    if(p.h==q.h){
        return p.w<q.w;
    }
    else{
        return p.h<q.h;
    }
}
void scan()
{
    int posb=1;
    for(int i=1;i<=n;i++){
        while(posb<=n){
            if(alice[i].h>=bob[posb].h){
                store.insert(bob[posb].w);
                posb++;
            }
            else{
                break;
            }
        }
        if(store.empty()) continue;
        else {
            multiset<int>::iterator iter=store.lower_bound(alice[i].w);
            if((*iter)==alice[i].w){
                store.erase(iter);re++;
            }
            else{
                if(iter==store.begin()) continue;
                else {
                    store.erase(--iter);re++;
                }
            }
        }
    }



}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        re=0;
        store.clear();
        scanf("%d",&n);
        LL h,w;
        for(int i=1;i<=n;i++){
            scanf("%I64d %I64d",&h,&w);
            alice[i].h=h;alice[i].w=w;
        }
        for(int i=1;i<=n;i++){
            scanf("%I64d %I64d",&h,&w);
            bob[i].h=h;bob[i].w=w;
        }
        sort(bob+1,bob+1+n,cmp);
        sort(alice+1,alice+n+1,cmp);
        scan();
        printf("%d\n",re);
    }

}
