#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
char s[420];
int k;
int main ()
{
    while(scanf("%s",s)!=EOF){
        scanf("%d",&k);
        int re=0;
        int len=strlen(s);
        if(k>=len){
            re=(len+k)>>1;
            re=re<<1;
            printf("%d\n",re);
            continue;
        }
        int m=k+len;
        int teplen;
        for(int i=0;i<len;i++){
            for(int j=1;j<=len-i;j++){
                teplen=0;
                for(int pos=i;pos<i+j;pos++){
                    if(pos+j>=len&&pos+j<m){
                        teplen++;
                    }
                    else if(s[pos]==s[pos+j]){
                        teplen++;
                    }
                }
                if(teplen==j){
                    re=max(re,j*2);
                }
            }
        }
        printf("%d\n",re);
    }
}

