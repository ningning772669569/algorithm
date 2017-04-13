#include <cstdio>
#include <iostream>
using namespace std;
int main ()
{
    int m,n;
    while(scanf("%d%d",&n,&m)==2){
        int re=99999;
        re=min(re,n+m-2);
        re=min(re,m);
        re=min(re,n);
        cout<<re<<endl;
    }
    return 0;
}
