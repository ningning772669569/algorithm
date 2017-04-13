#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long LL;
typedef pair<long long,long long> pll;
LL l,r,x;
LL step[70];
LL Re;
LL c[70][70];
LL ones(LL n)
{
    LL re=0;
    while(n){
        if(n & 1)
            re++;
        n/=2;
    }
    return re;
}
void init()
{
    c[1][1]=1;
    for(int i=1;i<=60;i++){
        c[i][1]=i;
        c[i][0]=1;
    }
    for(int i=1;i<=60;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            if(i==j)
                c[i][j]=1;
        }
    }

    memset(step,0,sizeof(step));
    step[1]=0;
    for(LL num=1;num<=60;num++){
        LL cur = num;
        LL ns=0;
        while(cur!=1){
            cur=ones(cur);
            ns++;
        }
        step[num]=ns;
    }
}
LL height(LL n)
{
    LL h=0;
    while(n){
        h++;
        n/=2;
    }
    return h;
}
LL get (LL r,LL n)
{
    LL tepre=0;
    LL hei=height(n);
    for(LL pos=n;pos<hei;pos++){
        tepre+=c[pos-1][n-1];
    }
    vector<pll> vec;
    LL h=0;
    LL num=0;
    while(n){
        h++;
        if(n&1)
            vec.push_back(make_pair(h,++num));
        n/=2;
    }
    //for(unsigned int i=0;i<vec.size();i++)
        //vec[i].second=num-vec[i].second+1;
    for(unsigned int i=0;!vec.empty() && i<vec.size()-1;i++){
        if(vec[i].first-1>= vec[i].second-1){
            LL a=vec[i].first-1;
            LL b=vec[i].second-1;
            tepre+=c[a][b];
        }
    }
    return tepre;
}
int main ()
{
    init();
    //cout<<c[5][2]<<endl;
    //for(int i=1;i<=10;i++)
        //cout<<i<<"  "<<step[i]<<endl;
        //cout<<get(1025,2)<<endl;
    while(scanf("%I64d%I64d%I64d",&l,&r,&x)==3 && x){
        Re=0;
        for(LL i=1;i<=60;i++)
            if(step[i]==x)
                if(l<=i && i<=r)
                    Re++;
        for(LL i=1;i<=60;i++){
            if(step[i]==x-1){
                Re+=get(r,i)-get(l,i);
            }
        }
        cout<<Re<<endl;
    }
    return 0;
}
