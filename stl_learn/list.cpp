#include <queue>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
list<int> l;
int main()
{
    for(int i=10;i>=0;i--)
        l.push_back(i);
    //sort(l.begin(),l.end());
    list<int>::iterator iter=l.begin();
    for(;iter!=l.end();iter++)
        cout<<*iter<<" ";
    return 0;
}
