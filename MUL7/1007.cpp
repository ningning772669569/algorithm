#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;

typedef long long LL;
const int maxn=200050;
const int INF=999999;
char teps[maxn];
char s[maxn];
int a[maxn];

LL sum;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        sum=0;
        s[0]='0';
        scanf("%s",teps);
        strcpy(s+1,teps);
        int len=strlen(teps);
        for(int i=1;i<=len;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<len;i++){
            if(s[i]=='?'){
                int lasti=i;
                while(s[i]=='?') i++;
                i--;
                if(i==len){
                    for(int j=lasti;j<=i;j++){
                        sum+=a[j];
                    }
                }
                else{
                    if(s[lasti-1]==s[i+1]){
                        int teplen=i-lasti+1;
                        if(teplen&1){
                            for(int j=lasti;j<=i+1;j++){
                                sum+=a[j];
                            }
                        }
                        else{
                            int MIN=INF;
                            for(int j=lasti;j<=i+1;j++){
                                sum+=a[j];
                                MIN=min(MIN,a[j]);
                            }
                            sum-=MIN;
                        }
                    }
                    else{

                        int teplen=i-lasti+1;
                        if(teplen&1){
                            int MIN=INF;
                            for(int j=lasti;j<=i+1;j++){
                                sum+=a[j];
                                MIN=min(MIN,a[j]);
                            }
                            sum-=MIN;
                        }
                        else{
                            for(int j=lasti;j<=i+1;j++){
                                sum+=a[j];
                            }
                        }

                    }
                }
            }
            else if(s[i+1]=='?'){
                continue;
            }
            else{
                if(s[i]!=s[i+1]){
                    sum+=a[i+1];
                }
            }
        }
        printf("Case #%d: %I64d\n",t,sum);
    }
    return 0;
}
