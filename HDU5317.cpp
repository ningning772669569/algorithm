#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
const int maxn =1000050;
int notpri[maxn];
unsigned short f[maxn][21];
vector<int> prime;
void init()
{
    memset(notpri,0,sizeof(notpri));
    memset(f,0,sizeof(f));
    for(int i=2;i<maxn;i++){
        if(!notpri[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i){
                notpri[j]=1;
            }
        }
    }
    for(int i=0;i<prime.size();i++){
        for(int j=prime[i];j<maxn;j+=prime[i]){
            f[j][0]++;
        }
    }
    for(int j=1;(1<<j)<maxn;j++){
        for(int i=1;i+(1<<j)<maxn;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int getmax(int l,int r)
{
    int k=0;
    while((1<<k)<=r-l+1) k++;
    k--;
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main ()
{
    init();
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",getmax(l,r));
    }

}
