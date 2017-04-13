#include "algorithm"
#include "cstdio"
#include "string"
using namespace std;
int main ()
{
    int m,n;//m是容量，n是代表一共有n个物品
    while (scanf("%d %d",&m,&n)==2&&m&&n){
        int d[n+2][m+2];
        int r[n+2];
        int v[n+2];
        for(int i=1;i<=n;i++){
            scanf("%d %d",r+i,v+i);
        }
       // memset(d,0,sizeof(d));
        for(int i=0;i<=n;i++){
            for (int j=0;j<=m;j++){
                if(i==0){
                    d[i][j]=0;
                }
                else{
                    d[i][j]=d[i-1][j];
                }
                if(j>=r[i]&&i>0){
                    if(d[i][j]<d[i-1][j-r[i]]+v[i])
                        d[i][j]=d[i-1][j-r[i]]+v[i];
                }
            }
        }
        printf("\n %d \n",d[n][m]);
    }
    return 0;
}
