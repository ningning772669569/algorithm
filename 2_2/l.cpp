#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "math.h"
using namespace std;
int n;
int k[1001];
int p[1001];
int r[1001];
int main ()
{
    while (scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&k[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&r[i]);
        }
        int knum=0,pnum=0;
        for(int i=1;i<=n;i++){
            if(abs(k[i]-r[i])>abs(p[i]-r[i])){
                pnum++;
            }
            if(abs(k[i]-r[i])<abs(p[i]-r[i])){
                knum++;
            }
        }
        printf("%d  %d\n",pnum,knum);
    }
    return 0;
}
