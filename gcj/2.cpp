#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL N;
set<int> s;
int main ()
{
    int T;
    cin >>T;
    for(int caseid=1;caseid<=T;caseid++){
        cin >>N;
        LL M=N;
        s.clear();
        cout<<"Case #"<<caseid<<": ";
        if(N==0){
            cout<<"INSOMNIA"<<endl;
            continue;
        }
        int flag=0;
        for(int times=1;times<=1000;times++){
            LL tepn=N;
            while(tepn){
                s.insert(tepn%10);
                tepn/=10;
            }
            if(s.size()==10){
                flag=1;
                cout<<N<<endl;
                break;
            }
            //cout<<N<<" "<<s.size()<<endl;
            N=N+M;
        }
        if(!flag)
            cout<<"INSOMNIA"<<endl;
    }
    return 0;
}
