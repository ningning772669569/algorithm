#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;

int n;
int q;
int num[1010];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            int MAX=0;
            for(int j=l;j<=r;j++){
                MAX=max(MAX,num[j]);
            }
            printf("%d\n",MAX);
        }

    }
    return 0;
}
