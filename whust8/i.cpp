#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;
char s1[70];
char s2[70];
int sum(char *s)
{
    int len=strlen(s);
    int a=0;
    for(int i=0;i<len;i++){
        a=a+s[i];
    }
    return a;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%s",s1);
        scanf("%s",s2);
        int sum1,sum2;
        sum1=sum(s1);
        sum2=sum(s2);
        if(abs(sum1-sum2)%2){
            printf("Case #%d: NO\n",t);
            continue;
        }
        int len=strlen(s1);
        if(len==2){
            int flag=0;
            for(int i=1;i<=26;i++){
                if(s1[0]==s2[0]&&s1[1]==s2[1]){
                    flag=1;
                    break;
                }
                char c=(s1[0]-'a'+1)%26+'a';
                s1[0]=(s1[1]-'a'+1)%26+'a';
                s1[1]=c;
            }
            if(flag){
                printf("Case #%d: YES\n",t);

            }
            else
                printf("Case #%d: NO\n",t);
        }
        else{
            printf("Case #%d: YES\n",t);
        }
    }
}
