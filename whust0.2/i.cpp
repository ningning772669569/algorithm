#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
#include "map"
using namespace std;
typedef long long LL;
const int maxn=35;
int n;
map<string,int> m;
int num[maxn];
int kinds;
LL sum;

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        string type;
        string name;
        scanf("%d",&n);
        m.clear();
        for(int i=1;i<=n;i++){
            cin>> name >>type;
            m[type]++;
        }
        kinds=-1;
        for(map<string,int>::iterator iter=m.begin();iter!=m.end();iter++){
            kinds++;
            num[kinds]=(*iter).second;

        }
        kinds++;
        sum=1;
        for(int i=0;i<kinds;i++){
            sum*=num[i]+1;
        }
        printf("%I64d\n",sum-1);
    }
}
