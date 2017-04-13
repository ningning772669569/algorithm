#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL ten[30];
LL get(LL n)
{
    LL tep=1;
    while(n){
        tep=tep*(n%10);
        n/=10;
    }
    return tep;
}
int main ()
{
    ten[0]=1;
    for(int i=1;i<=29;i++)
        ten[i]=ten[i-1]*10;
    LL a,b;
    while(scanf("%I64d %I64d",&a,&b)==2){
    LL MAX=get(b);
    LL re=b;
    for(int pos=1;pos<18;pos++){
        LL tepb = b;
        vector<int> tepre;
        tepre.clear();
        for (int i=1;i<=pos && tepb;i++){
            if(tepb%10==9){
                tepb/=10;
                tepre.push_back(9);
            }
            else if(tepb>=10){
                tepb/=10;
                tepb-=1;
                tepre.push_back(9);

            }
            else{
                tepre.push_back(tepb%10);
                tepb/=10;
            }
        }
        LL cur=0;
        for(int i=tepre.size()-1;i>=0;i--){
            cur=cur*10+tepre[i];
        }
        cur=tepb*ten[tepre.size()]+cur;
        if(cur<a)
            continue;
        if(get(cur)>MAX){
            MAX=get(cur);
            re=cur;
        }
    }
    cout<<re<<endl;
    }
    return 0;
}
