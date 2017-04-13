#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
const int maxn =1000050;
int notpri[maxn];
int num[maxn];
int f[maxn][10];
vector<int> prime;
void init()
{
    memset(notpri,0,sizeof(notpri));
    memset(f,0,sizeof(f));
    memset(num,0,sizeof(num));
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
            num[j]++;
        }
    }
    for(int i=2;i<maxn;i++){
        int tep=num[i];
        for(int k=1;k<=8;k++)
            f[i][k]=f[i-1][k];
        f[i][tep]++;

    }
}
int gcd(int a,int b)
{
    return b==0? a:gcd(b,a%b);
}
int getmax(int l,int r)
{
    int re[10];
    int MAX=0;
    memset(re,0,sizeof(re));
    for(int i=0;i<9;i++){

        re[i]=f[r][i]-f[l-1][i];
        cout<<i<<"    "<<re[i]<<endl;
    }
    for(int i=1;i<9;i++){
        if(re[i]>=2)
            MAX=max(MAX,i);
        if(re[i])
            for(int j=i+1;j<9;j++){
                if(re[j]){
                    MAX=max(MAX,gcd(i,j));
                }
            }
    }
    return MAX;
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
