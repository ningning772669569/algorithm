#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int T;
    cin>>T;
    for(int caseid=1;caseid<=T;caseid++){
        string pan;
        cin >>pan;
        int num=0;
        int l=0;
        while(l<pan.size()){
            int r=l+1;
            while(r<pan.size()&&pan[r]==pan[l])
                r++;
            num++;
            l=r;
        }
        int re=num-1;
        if(pan[pan.size()-1]=='-')
            re++;
        cout<<"Case #"<<caseid<<": "<<re<<endl;

    }
    return 0;
}
