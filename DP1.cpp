#include "cstdio"
#include "algorithm"
#include "iostream"
#include "cstring"
using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    int num[n+2][n+2];
    int d[n+2][n+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&num[i][j]);
        }
    }
    memset(d,0,sizeof(d));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            d[i][j]=num[i][j]+max(d[i+1][j],d[i+1][j+1]);
        }
    }
    cout <<d[1][1]<<endl;
    return 0;
}
