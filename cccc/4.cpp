#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
#include "map"
#include "set"
using namespace std;
int N;
int K;
int Q;
int main ()
{
    cin >>N;
    set<string> s;
    map<string,int> m;
    for(int caseid=1;caseid<=N;caseid++){
        cin >>K;
        if(K<2){
            string tep;
            cin>>tep;
            continue;
        }
        for(int i=1;i<=K;i++){
            string tep;
            cin >>tep;
            m[tep]++;
        }
    }
    s.clear();
    vector<string> re;
    cin>>Q;
    for(int i=1;i<=Q;i++){
        string tep;
        cin >>tep;
        if(s.count(tep))
            continue;
        s.insert(tep);
        if(m[tep]==0)
            re.push_back(tep);
    }
    for(int i=0;i<re.size();i++){
        cout<<re[i];
        if(i<re.size()-1)
            cout<<" ";
    }
    if(re.empty())
        cout<<"No one is handsome";
    return 0;
}
