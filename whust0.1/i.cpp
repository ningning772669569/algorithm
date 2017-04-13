#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn=1e5+20;
int l[maxn];
int o[maxn];
LL num[maxn];
LL sum[maxn];
int main ()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int t=1;t<=T;t++){
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        memset(l,0,sizeof(l));
        memset(o,0,sizeof(o));
        int pos=0;
        int posl=0;
        int poso=0;
        char c;
        c=getchar();
        while(c!='\n'){
            if(c=='L'){
                l[posl]=pos;
                posl++;
            }
            else{
                o[poso]=pos;
                poso++;
            }
            pos++;
            c=getchar();
        }
        int sizel=posl;posl--;
        int sizeo=poso;poso--;
        for(int i=0;i<sizeo;i++){
            int * a=lower_bound(l,l+sizel,o[i]);
            LL tepnum=sizel-(a-l);
            num[i]=tepnum;
        }
        sum[poso]=num[poso];
        for(int i=poso-1;i>=0;i--){
            sum[i]=sum[i+1]+num[i];
        }
        LL all=0;
        for(int i=0;i<sizel;i++){
            int * a=lower_bound (o,o+sizeo,l[i]);
            all+=sum[a-o];
        }
        printf("%I64d\n",all);
    }
}

