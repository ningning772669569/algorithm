#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=5010;
int num1[maxn];
int num2[maxn];
int num[maxn];
char s1[maxn];
char s2[maxn];
int main ()
{
    while(scanf("%s %s",s1,s2)!=EOF){
        int len1=strlen(s1);
        int len2=strlen(s2);
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        for(int i=len1-1;i>=0;i--){
            num1[len1-i]=s1[i]-'0';
        }
        for(int i=len2-1;i>=0;i--){
            num2[len2-i]=s2[i]-'0';
        }
        int len=max(len1,len2);
        int c=0;
        int times=0;
        for(int i=1;i<=len;i++){
            num[i]=num1[i]+num2[i]+c;
            c=num[i]/2;
            if(c){
                times++;
            }
            num[i]=num[i]%2;
        }
        int j=1;
        while(times>0){

            while(num[j]==1) j++;
            if(j>times){

                num[j-times]=0;
                break;
            }
            else{
                num[j]=1;
                times=times-j;
            }
        }
        for(int i=maxn-1;i>1;i--){
            if(num[i]&&num[i-1]){
                num[i+1]=1;
                num[i]=num[i-1]=0;
            }
        }
        for(int i=1;i<maxn-2;i++){
            if(num[i]&&num[i+1]){
                num[i]=num[i+1]=0;
                num[i+2]=1;
            }
        }
        int tep=maxn-1;
        while(!num[tep]) tep--;
        for(int i=tep;i>=1;i--){
            printf("%d",num[i]);
        }
        printf("\n");
    }
}
