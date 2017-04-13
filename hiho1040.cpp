#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
struct seg{
    int x1,y1,x2,y2;
};
vector<seg> v;
set<pii> s;
int have(seg d,pii a)
{
    if((d.x1==a.first) && (d.y1==a.second))
        return 1;

    if((d.x2==a.first) && (d.y2==a.second))
        return 1;
    return 0;

}
int check(int pos)
{
    pii a=make_pair(v[pos].x1,v[pos].y1);
    pii b=make_pair(v[pos].x2,v[pos].y2);
    vector<int> tepv;
    for(int i=0;i<4;i++){
        if(i==pos)
            continue;
        pii c=make_pair(v[i].x1,v[i].y1);
        pii d=make_pair(v[i].x2,v[i].y2);
        if(((b.second-a.second)*(c.second-d.second))==((d.first-c.first)*(b.first-a.first))){
            //cout<<"***"<<i<<endl;
            tepv.push_back(i);
        }
    }
    //cout<<"&&"<<tepv.size()<<endl;;
    if(tepv.size()!=2)
        return 0;
    int fa=0,fb=0;
    for(int i=0;i<2;i++){
        if(have(v[tepv[i]],a))
            fa=1;
        if(have(v[tepv[i]],a))
            fb=1;

    }
    return fa&&fb;

}
int main ()
{
    int T;
    cin >>T;
    for(int caseid=1;caseid<=T;caseid++){
        v.clear();
        s.clear();
        for(int i=1;i<=4;i++){
            int x1,y1,x2,y2;
            cin >>x1>>y1>>x2>>y2;
            v.push_back((seg){x1,y1,x2,y2});
            s.insert(make_pair(x1,y1));
            s.insert(make_pair(x2,y2));
        }
        if(s.size()!=4)
        {
            cout<<"NO"<<endl;
            continue;
        }
        //cout<<s.size()<<endl;
        int flag=1;
        for(unsigned int i=0;i<4;i++){
            if(!check(i)){
                flag=0;
                //cout<<"!!"<<i<<endl;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
