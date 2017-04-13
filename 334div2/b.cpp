#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=110009;
int N,K;
int s[maxn];
int main ()
{
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++)
        scanf("%d",&s[i]);
    int sig=2*K-N;
    int re=s[N-sig]+s[1];
    re=max(s[N],re);
    cout<<re<<endl;
}
