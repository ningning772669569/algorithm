#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "utility"
#include "set"
using namespace std;
typedef pair<int,int> pii;
pii point[35];
set<pii> s;
set<pii> s2;
int N;
int have(pii a,pii b,pii c,pii d)
{
    int li=min(a.first,b.first);
    int la=max(a.first,b.first);
    int hi=min(a.second,b.second);
    int ha=max(a.second,b.second);
    int lli=min(c.first,d.first);
    int lla=max(c.first,d.first);
    int hhi=min(c.second,d.second);
    int hha=max(c.second,d.second);
    if(li<lli && lla<la && hi<hhi && hha<ha)
        return 1;
    if(lli<li && la<lla && hhi<hi && ha<hha)
        return 1;
    return 0;
}
int check2(pii a,pii b,pii c,pii d)
{
    int li=min(a.first,b.first);
    int la=max(a.first,b.first);
    int hi=min(a.second,b.second);
    int ha=max(a.second,b.second);
    int lli=min(c.first,d.first);
    int lla=max(c.first,d.first);
    int hhi=min(c.second,d.second);
    int hha=max(c.second,d.second);
    if(la < lli || li >lla)
        return 1;
    if(ha <hhi || hi>hha)
        return 1;
    return 0;
}
int main ()
{
    while(scanf("%d",&N)==1 && N){
        s.clear();
        for(int i=1;i<=N;i++)
            scanf("%d %d",&point[i].first,&point[i].second);
        //sort(point+1,point+1+N);
        for(int i=1;i<=N;i++){
           s.insert(point[i]);
        }
        if(N<8){
            printf("imp\n");
            continue;
        }
        int re=0;
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                s2.clear();
                if(point[i].first==point[j].first) continue;
                if(point[i].second==point[j].second) continue;
                pii t1; t1.first=point[i].first; t1.second=point[j].second;
                pii t2; t2.first=point[j].first; t2.second=point[i].second;
                if(s.count(t1) && s.count(t2) ){
                    s2.insert(t1);s2.insert(t2);s2.insert(point[i]);s2.insert(point[j]);
                    for(int k=1;k<=N;k++){
                        for(int m=k+1;m<=N;m++){
                            if(s2.count(point[k]) || s2.count(point[m])) continue;
                            if(point[k].first==point[m].first) continue;
                            if(point[k].second==point[m].second) continue;
                            pii t3; t3.first=point[k].first; t3.second=point[m].second;
                            pii t4; t4.first=point[m].first; t4.second=point[k].second;
                            if(s2.count(t3) || s2.count(t4)) continue;
                            if((!s.count(t3)) || (!s.count(t4))) continue;
                            int flag=0;
                            if(have(t1,t2,t3,t4))
                                flag=1;
                            if(!check2(t1,t2,t3,t4) && (!flag))
                                continue;
                            int l1=abs(point[i].first-point[j].first);
                            int l2=abs(point[i].second-point[j].second);
                            int l3=abs(t3.first-t4.first);
                            int l4=abs(t3.second-t4.second);
                            if(!flag)
                                re=max(re,l1*l2+l3*l4);
                            else
                            {
                                int t;
                                t=max(l1*l2,l3*l4);
                                re=max(re,t);

                            }
                        }
                    }
                }
            }
        }
        if(re)
            printf("%d\n",re);
        else
            printf("imp\n");
    }
}
