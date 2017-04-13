#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;
int n,m;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d  %d",&n,&m);
        for(int i=1;i<=m;i++){
            int from,to;
            scanf("%d  %d",&from,&to);
        }
        printf("%d\n",n-1);
    }
}
