#include "cstdio"
#include "cstring"
#include "iostream"
#include "queue"
#include "algorithm"
#include "utility"
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=150010;
struct Person{
    int v;
    int time;
    bool operator < (const Person & rhs) const
    {
        if(v!=rhs.v)
            return v<rhs.v;
        else
            return time>rhs.time;

    }
};
struct open{
    int t,p;
};
bool cmp(const struct open &p,const open & q)
{
    return p.t<q.t;

}
struct Person person[maxn] ;
struct open  o[maxn];
priority_queue <Person> pq;
vector<string> name;
int qu[110];
int order[maxn];
int k,m,query;
char cname[210];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        while(!pq.empty())
            pq.pop();
        name.clear();
        name.push_back("");
        scanf("%d %d %d",&k,&m,&query);
        for(int i=1;i<=k;i++){
            scanf("%s %d",cname,&person[i].v);
            string tepname(cname);
            //cin>>tepname>>person[i].v;
            person[i].time=i;
            name.push_back(tepname);
        }
        int MAX=0;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&o[i].t,&o[i].p);

        }
        sort(o+1,o+1+m,cmp);
        for(int i=1;i<=query;i++){
            scanf("%d",&qu[i]);
            MAX=max(MAX,qu[i]);
        }
        memset(order,0,sizeof(order));
        int flag=0;
        int cp=1;
        int ot=1;
        int inum=0;
        while(ot<=m){

            while(cp<=k&&o[ot].t>=cp){

                pq.push(person[cp]);
                cp++;
            }
            if(o[ot].p>=pq.size()){
                while(!pq.empty()){
                    Person tep=pq.top();
                    pq.pop();
                    inum++;
                    order[inum]=tep.time;
                }
            }
            else{
                int tt=o[ot].p;
                while(tt){
                    Person tep=pq.top();
                    pq.pop();
                    inum++;
                    order[inum]=tep.time;
                    tt--;
                }
            }
            if(inum>MAX){
                flag=1;
                break;
            }
            ot++;
        }
        if(!flag){
        while(cp<=k){

            pq.push(person[cp]);
            cp++;

        }

        while(!pq.empty()){
            Person tep=pq.top();
            pq.pop();
            inum++;

            order[inum]=tep.time;
            if(inum>=MAX)
                break;
        }}
        for(int i=1;i<=query;i++){
            int tt=qu[i];

            cout<<name[order[tt]];
            if(i<query)
                printf(" ");
        }
        cout<<endl;;
    }
    return 0;
}
