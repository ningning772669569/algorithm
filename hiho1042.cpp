#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,L;
int l,r,t,b;
map<int,int> mm;
int vis[10];
int up[4]={n,m,n,m};
pii get(int len,int high,int last)
{
    int re=0;
    int relen;
    int tlen=0;
    for(tlen=len;tlen>=1;tlen--){
        if(2*tlen+2>last)
            continue;
        int tlast=last;
        int sum=0;
        sum+=tlen;
        tlast-=2*tlen+2;
        sum+=tlen*(min(tlast/2,high-1));
        //re=max(re,sum);
        if(re<sum){
            re=sum;
            relen=tlen;
        }
    }
    return make_pair(re,relen);

}

pii get2(int len,int high,int last)
{
    int re=0;
    int relen;
    int tlen=0;
    for(tlen=len;tlen>=1;tlen--){
        if(tlen+2>last)
            continue;
        int tlast=last;
        int sum=0;
        sum+=tlen;
        tlast-=tlen+2;
        sum+=tlen*(min(tlast/2,high-1));
        //re=max(re,sum);
        if(re<sum){
            re=sum;
            relen=tlen;
        }
    }
    return make_pair(re,relen);

}

int start(int pos)
{
    memset(vis,0,sizeof(vis));
    int last=L;
    int sum=0;
    int hnum=1;
    vector<int> vec;
    vec.push_back(pos);
    vis[pos]=1;
    if(last<2*(up[pos]+mm[pos])){
        return get(mm[pos],up[pos],last).first;
    }
    sum+=mm[pos]*up[pos];
    last-=2*(up[pos]+mm[pos]);
    vis[pos]=1;
    int lastpos=pos;
    int newpos;
    while(last>=2){
        priority_queue<pii> pq;
        while(!pq.empty())
            pq.pop();
        for(int i=0;i<vec.size();i++){
            int cur=vec[i];
            int a=(cur+4-1)%4;
            int b=(cur+1)%4;
            //cout<<"mma   "<<vis[a]<<"   "<<mm[a]<<endl;
            //cout<<"mmb   "<<vis[b]<<"   "<<mm[b]<<endl;
            if((!vis[a])&& mm[a]>0)
                pq.push(make_pair(mm[a],a));
            if((!vis[b]) && mm[b]>0)
                pq.push(make_pair(mm[b],b));
            //cout<<"!!"<<pq.size()<<endl;
        }
        if(pq.empty())
            return sum;
        pii tep=pq.top();
        int cur=tep.second;
        vis[cur]=1;
        vec.push_back(cur);
        int high=up[cur];
        if(vis[(cur+4-1)%4])
            high-=mm[(cur+4-1)%4];
        if(vis[(cur+1)%4])
            high-=mm[(cur+1)%4];
        if(last<2*(high+mm[cur])){
            pii tepre=get2(mm[cur],high,last);
            return sum+tepre.first;
        }
        else{
            last-=2*(high+mm[cur]);
            sum+=high*mm[cur];
        }
        /*int tepnum=0;
        while(last>=2&&tepnum<high){
            tepnum++;
            sum+=mm[cur];
            last-=2;
        }*/

    }
    return sum;
}
int main ()
{
    cin >>n>>m>>L;
    cin >>l>>r>>b>>t;
    up[0]=up[2]=n;
    up[1]=up[3]=m;
    int lk,rk,tk,bk;
    lk=l;rk=m-r;
    bk=b;tk=n-t;
    mm[0]=l;mm[1]=bk;
    mm[2]=rk;mm[3]=tk;
    cout<<lk<<" "<<bk<<" "<<rk<<" "<<tk<<endl;
    int re=0;
    for(int i=0;i<4;i++){
        if(mm[i]>0)
            re=max(start(i),re);
    }
    cout<<re<<endl;
    return 0;
}
