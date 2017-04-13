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
#include <list>
using namespace std;
list <char> s;
string ins, cp;
int emod, cmod;
unsigned M;
list<char>::iterator cp1=s.end();
list<char>::iterator cp2;
int cmp(list<char>::iterator a,list<char>::iterator b)
{
    while(a!=b && a!=s.end()){
        a++;
    }
    if(a==b)
        return 1;
    else{
        return 0;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        s.clear();
        cp.clear();
        list<char>::iterator pos=s.end();
        cin>>M>>ins;
        emod=cmod=0;
        cp1=s.end();
        for(auto &&c: ins){
//            cout<<c<<endl;
            if(c=='L'){
                if(pos!=s.begin()){
                    --pos;
                }
            }
            else if(c=='R'){
                if(pos!=s.end()){
                    ++pos;
                }
            }
            else if(c=='S'){
                if(emod==0){
                    emod=1;
                }
                else{
                    emod=0;
                }
            }
            else if(c=='D'){
                if(cmod==0){
                    if(pos!=s.end()){
                        pos=s.erase(pos);
                    }
                }
                else{
                    cmod=0;
                }
            }
            else if(c=='B'){
                if(cmod==1){
                    cmod=0;
                }
                if(s.size()>=1&&pos!=s.begin()){
                    --pos;
                    pos=s.erase(pos);
                }
            }
            else if(c=='C'){
                if(cmod==1){
                    cp2=pos;
                    int big=cmp(cp1,cp2);
                    if(big){
                        while(cp1!=cp2){
                            cp1++;
                            cp.insert(*cp1);
                        }
                    }
                    else{
                        while(cp2!=cp1){
                            cp2++;
                            cp.insert(*cp2);
                        }
                    }
                    cmod=0;
                    cp.clear();
                }
                else{
                    cmod=1;
                    cp1=pos;
                }
            }
            else if(c=='V'){
                /*if(cmod==1){
                    cmod=0;
                }*/
                if(emod==0){
                    if(!cp.empty())
                        s.insert(pos,cp.begin(),cp.end());
                }
                else{
                    if(!cp.empty()){
                        list<char>::iterator tt=pos+1;
                        int ss=cp.size();
                        s.insert(pos,cp.begin(),cp.end());
                        while(ss&&tt!=s.end()){
                            list<char>:iterator tep=tt;
                            tt++;
                            s.erase(tep);
                            ss--;
                        }
                    }
                    ;
                }
            }
            else{
                if(cmod==1){
                    cmod=0;
                }
                if(s.size()>=M){
                    continue;
                }
                if(pos==s.end()){
                    s.insert(pos, c);
                }
                else if(emod==0){
                    s.insert(pos, c);
                }
                else{
                    *pos=c;
                    ++pos;
                }
            }
        }
        if(s.size()==0){
            cout<<"NOTHING\n";
        }
        else{
            for(auto i=s.begin(); i!=s.end(); ++i){
                cout<<*i;
            }
            cout<<'\n';
        }
    }
    return 0;
}

