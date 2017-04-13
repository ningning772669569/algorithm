#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int a[100008];
int b[100008];
int pos[100008];
int vis[100008];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=n;i++)
            pos[a[i]]=i;
        int re=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(!vis[a[i]] && a[i]!=b[i]){
                re++;
                int temp=a[i];
                while(!vis[temp]){
                    vis[temp]=1;
                    int p=pos[temp];
                    temp=b[p];
                }
            }
        }
        printf("%d\n",n-re);
    }
}
