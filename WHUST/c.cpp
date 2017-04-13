#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=100009;
bool vis[maxn*4];
int num[maxn];
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int a=num[i]-num[j];
                if(vis[a+200000]){
                    sum++;
                    break;
                }
            }
            for(int j=1;j<=i;j++){
                int a=num[i]+num[j];
                vis[a+200000]=true;
            }
        }

        printf("%d\n",sum);
    }
}
