#include "cstdio"
#include "cstring"
#include "algorithm"
#include "stack"
#include "iostream"
using namespace std;
stack <string> bac,forw;
string cur;
string order;
string url;
int main ()
{
    cur="";
    string tep="http://www.acm.org/";
    bac.push(tep);
    while(1){
        cin >> order;
        if(order=="VISIT"){
            cin >> url;
            cout << url << endl;
            if(cur!="")
                bac.push(cur);
            cur=url;
            while(!forw.empty())
                forw.pop();
        }
        else if(order=="BACK"){
            if(bac.empty()){
                cout << "Ignored"<<endl;
                continue;
            }
            if(cur!="")
            forw.push(cur);
            cur=bac.top();
            cout<<cur<<endl;
            bac.pop();
        }
        else if(order=="FORWARD"){
            if(forw.empty()){
                cout<<"Ignored"<<endl;
                continue;
            }
            bac.push(cur);
            cur=forw.top();
            cout << cur<<endl;
            forw.pop();
        }
        else{
            break;
        }
    }
    return 0;
}
