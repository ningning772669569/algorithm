#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int num[2000];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int Q;
        scanf("%d",&Q);
        int l,r;
        for(int q=1;q<=Q;q++){
            scanf("%d%d",&l,&r);
            int MAX=num[l];
            for(int j=l;j<=r;j++){
                if(num[j]>MAX)
                    MAX=num[j];
            }
            cout<<MAX<<endl;
        }
    }
}
