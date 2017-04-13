#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
struct node{
    int i;
    node(int n):i(n){}
    node(){}
    bool operator <(const node & p) const {
        return i<p.i;
    }
    bool operator >(const node & p)const {
        return i>p.i;
    }
};
priority_queue<node,vector<node>,greater<node> >pqmin;
priority_queue<node> pqmax;
int main ()
{
    for(int i=1;i<=10;i++){
        pqmin.push(node(i));
        pqmax.push(node(i));
    }
    for(int i=1;i<=10;i++){
        node tep=pqmin.top();
        cout<<tep.i<<" ";
        pqmin.pop();
    }
    cout<<endl;
    for(int i=1;i<=10;i++){
        node tep=pqmax.top();
        cout<<tep.i<<" ";
        pqmax.pop();
    }
    return 0;
}
