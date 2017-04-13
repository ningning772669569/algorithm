#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
char s[1000009];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%s",s);
        int len=strlen(s);
        int pos=0;
        while(pos<len&&s[pos]=='f') pos++;
        if(pos==len){
            printf("Case #%d: %d\n",t,len&1?len/2+1:len/2);
            continue;
            }
        int start=pos;
        for(int i=0;i<pos;i++){
            s[len++]='f';
        }
        s[len]='\0';
        int num=0;
        int flag=1;
        while(start<len){
            int p=start+1;
            while(p<len&&s[p]=='f') p++;
            if(p-1-start<2){
                flag=0;
                break;
            }
            else{
                num++;
                start=p;
                if(p==len)
                    break;
            }

        }
        if(flag)
            printf("Case #%d: %d\n",t,num);
        else
            printf("Case #%d: -1\n",t);
    }
}
