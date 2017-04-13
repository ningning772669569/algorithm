#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;


char s[110];
char t[110];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        scanf("%s",s);
        scanf("%s",t);
        int len =strlen(s);
        int num0,num1,znum,onum,wnum;
        num0=num1=onum=znum=wnum=0;
        for(int i=0;i<len;i++){
            if(s[i]=='0'){
                znum++;
            }
            else if(s[i]=='1'){
                onum++;
            }
            else{
                wnum++;
            }
            if(t[i]=='0'){
                num0++;
            }
            else{
                num1++;
            }
        }
        if(onum>num1||znum>num0||znum+wnum<num0||onum+wnum<num1){
            printf("Case %d: -1\n",tt);
            continue;
        }
        int sum1=0,sum2=0;
        for(int i=0;i<len;i++){
            if(s[i]=='?'){
                int c=t[i]-'0';
                if(c){
                    if(onum<num1){
                        onum++;
                        sum1++;
                    }
                }
                else{
                    if(znum<num0){
                        znum++;
                        sum1++;
                    }
                }
            }
            else{
                if(s[i]!=t[i]){
                    sum2++;
                }
            }
        }
        printf("Case %d: %d\n",tt,wnum+(sum2+wnum-sum1)/2);
    }
}
