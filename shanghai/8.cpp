#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <iomanip>
#include <utility>
#include <bitset>
typedef long long  ll;
using namespace std;
ll q, m, x=1, g;
ll gcd(ll a, ll b){
    return b==0?a:gcd(b, a%b);
}
void exgcd(ll a, ll b,ll &d,ll &x,ll &y){
     if(!b){
          d=a;x=1;y=0;
     }
     else{
          exgcd(b,a%b,d,y,x);
          y-=x*(a/b);
     }
}
ll inv(ll a,ll n){
     ll d,x,y;
     exgcd(a,n,d,x,y);
     return d==1?(x+n)%n:-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        x=1;
        cout<<"Case #"<<i<<":\n";
        cin>>q>>m;
        vector<ll> sc;
        sc.resize((unsigned)(q+5));
        for(int k=1; k<=q; k++){
            ll tp, nu;
            cin>>tp>>nu;
            if(tp==1){
                if(x==0)
                    x=m;
                x=x*nu;
                sc[k]=nu;
                cout<<x%m<<'\n';
                if(x%m!=0){
                    x=x%m;
                }
                if(x==0)
                    x=m;
            }
            else{
                g=0;
                if(x==0){
                    x=m;
                }
                if((g=gcd(m, sc[nu]))==1){
                    x=x*inv(sc[nu], m);
                    cout<<x%m<<'\n';
                    if(x%m!=0){
                        x=x%m;
                    }
                }
                else{
                    x=(x/g)*inv(sc[nu]/g, m/g);
                    cout<<x%(m/g)<<'\n';
                    if(x%(m/g)!=0){
                        x%=m;
                    }
                }
            }
        }
    }
    return 0;
}
