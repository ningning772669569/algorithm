#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#define MAX 62
using namespace std;
typedef long long LL;
int n;
LL c[MAX][MAX];
void init()
{
    memset(c,0,sizeof(c));

    for(int i=1;i<MAX;i++){
        c[i][0]=1;
        c[i][1]=i;
    }
    for(int i=2;i<MAX;i++){
        for(int j=2;j<=i;j++){
            if(i==j){
                c[i][j]=1;
            }
            else {
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
}
LL getnum(int n)
{
    return c[2*n][n]-c[2*n][n-1];
}
int main ()
{
    init();
    while (scanf("%d",&n)!=EOF&&n){
        printf("%I64d\n",getnum(n));

    }

}

