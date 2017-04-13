#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;
LL x1,yy1,x2,y2;
LL x3,y3,x4,y4;
LL height ,weight;
vector<pll> vec;
int main ()
{
    freopen("grave.in","r",stdin);
    freopen("grave.out","w",stdout);
    cin >>x1>>yy1>>x2>>y2;
    cin >> x3>>y3>>x4>>y4;
    vec.push_back(make_pair(x2-x1,y3-yy1));
    vec.push_back(make_pair(x2-x4,y2-yy1));
    vec.push_back(make_pair(x2-x1,y2-y4));
    vec.push_back(make_pair(x3-x1,y2-yy1));
    cin >>weight>>height;
    int flag=0;
    for(int i=0;i<=3;i++){
        LL a=vec[i].first;
        LL b=vec[i].second;

        if(a>=weight && b>=height){
            flag=1;
            break;
        }

    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
