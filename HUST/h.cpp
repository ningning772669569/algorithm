#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
const int max_n = 1100;
map<int,int> mp;
int a[max_n];
pair<int,int> p[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        mp.clear();
        int numzero = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
            if(a[i]==0){
                numzero++;
            }
        }
        int pos = 0;
        for(map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
            p[pos].first = it->first;
            p[pos].second = it->second;
            //cout<<p[pos].first<<"  "<<p[pos].second<<endl;
            pos++;
        }
        ll ans = 0;
        int tmpzero = 1;
        if(numzero>=3){
            ans=numzero*(numzero-1)*(numzero-2);
        }
        //cout<<"$"<<pos<<endl;
        for(int i = 0;i<pos;i++){
            for(int j = i+1;j<pos;j++){

                int tmp = p[i].first+p[j].first;
                tmp = -tmp;
                if(mp.count(tmp)&&tmp!=p[i].first&&tmp!=p[j].first){
                    ans+=2*mp[tmp]*p[i].second*p[j].second;
                }
            }
            int tmp=2*p[i].first;
            tmp=-tmp;
            if(mp[tmp]){
                int tep=p[i].second;
                tep=tep*(tep-1)/2;
                ans+=6*mp[tmp]*tep;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
