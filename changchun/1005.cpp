#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "map"
#include "set"
using namespace std;
typedef long long LL;
const int maxn=20100;
const int maxm=100100;
struct Road{
    int l,r,c;
};
struct Query{
    int len;
    int i;
};
int f[maxn];
int num[maxn];
int n,m,q;
Query query[5500];
Road r[maxm];
int re[5500];
map<int,int> mm;
set<int> s;
bool cmp(const Road &p ,const Road &q)
{
    return p.c<q.c;
}
bool cmp2(const Query &p,const Query &q)
{
    return p.len<q.len;
}
int find(int v)
{
    return f[v]==v ? v:f[v]=find(f[v]);
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        mm.clear();
        s.clear();
        scanf("%d %d %d",&n,&m,&q);
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            f[i]=i;
            num[i]=1;
        }

        for(int i=1;i<=m;i++){

            scanf("%d %d %d",&r[i].l,&r[i].r,&r[i].c);
        }
        sort(r+1,r+1+m,cmp);
        for(int i=1;i<=q;i++){
            scanf("%d",&query[i].len);
            query[i].i=i;
        }
        sort(query+1,query+1+q,cmp2);

        int qnum=1;
        int rnum=1;

        while(qnum<=q){
            while(rnum<=m&&r[rnum].c<=query[qnum].len){
                 //cout<<"*******"<<endl;
                int u=find(r[rnum].l);
                int v=find(r[rnum].r);
                if(u!=v){
                    f[u]=v;
                    num[v]+=num[u];
                    num[u]=0;
                    set<int>::iterator iter=s.find(u);
                    if(iter!=s.end()){
                        s.erase(iter);
                    }
                    if(s.count(v)==0)
                        s.insert(v);

                }
                //cout<<"*******"<<endl;
                rnum++;
            }
            //cout<<"^^^^^"<<endl;
            LL sum=0;
            set<int>::iterator a=s.begin();
            while(a!=s.end()){
                    sum+=num[*a]*(num[*a]-1);
                    a++;
            }
            re[query[qnum].i]=sum;
            qnum++;
        }
        for(int i=1;i<=q;i++)
            printf("%d\n",re[i]);

    }
    return 0;
}
