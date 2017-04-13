#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
using namespace std;
const int maxn=1e5+20;
struct Node{
    int l;int r;
    int num;
};
int n;
struct Node soda[maxn];
vector<int> invite;
typedef pair<int,int> pii;
set<pii>s;
int vis[maxn];
bool cmp(const struct Node &p,const struct Node &q)
{
    if(p.l!=q.l){
        return p.l<q.l;
    }
    else{
        return p.r<q.r;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int num;
            scanf("%d",&num);
            soda[i].l=num;
            soda[i].num=i;
        }
        for(int i=1;i<=n;i++){
            int num;
            scanf("%d",&num);
            soda[i].r=num;
        }
        sort(soda+1,soda+1+n,cmp);
        int sum=0;
        invite.clear();
        s.clear();
        int i=1;
        while(i<=n){
            if(sum<soda[i].r||i>n)
                break;
            while(sum>=soda[i].l){
                s.insert(make_pair(soda[i].r,soda[i].num));
                i++;
            }
            set<pii>::iterator iter=s.lower_bound(make_pair(sum,0));
            if((*iter).first>=sum){
                sum++;
                invite.push_back((*iter).second);
                s.erase(iter);
            }
        }
        printf("%d\n",sum);
        memset(vis,0,sizeof(vis));
        for(vector<int>::size_type a=0;a<invite.size();a++){
            printf("%d",invite[a]);
            vis[invite[a]]=1;
            if(a<invite.size()-1){
                printf(" ");
            }
        }
        if(invite.size()==n)
            continue;
        printf(" ");
        for(int i=1;i<=n;i++){
            if(!vis[i])
                printf("%d ",i);
        }
        printf("\n");
    }

}
