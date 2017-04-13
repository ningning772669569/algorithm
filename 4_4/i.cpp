#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "set"
using namespace std;
typedef long long LL;
int n,p;
set<LL> s;
void divide(LL pro,int n)
{
    for(int i=1;i<n/2;i++){
        LL tep=i*(n-i);
        tep=(tep*pro)%p;
        s.insert(tep);
        divide(tep,i);
        divide(tep,n-i);
    }
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        s.clear();
        scanf("%d %d",&n,&p);
        divide(1,n);
        printf("%d",s.size());
    }
}
