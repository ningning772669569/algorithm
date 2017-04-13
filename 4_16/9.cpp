#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
int N;
int T;
pair<LL,LL> num[1000009];
LL mi[1000009];
LL ma[1000009];
int main ()
{
    cin >>T;
    while(T--){
        cin >>N;
        for(int i=1;i<=N;i++){
            scanf("%lld",&num[i].first);
            num[i].second=i;
        }
        sort(num+1,num+1+N);
        LL tepmi=N+10;
        LL tepma=-1;
        for(int i=N;i>=1;i--){
            tepmi=min(tepmi,num[i].second);
            tepma=max(tepma,num[i].second);
            mi[i]=tepmi;
            ma[i]=tepma;
        }
        LL re=0;
        for(int i=1;i<=N;i++){
            re=max(re,abs(mi[i]-num[i].second)*num[i].first);
            re=max(re,abs(ma[i]-num[i].second)*num[i].first);
        }
        cout<<re<<endl;
    }
    return 0;
}
