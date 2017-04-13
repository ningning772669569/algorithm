#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n;
char s[101][1010];
char d[1010];
char x[1010];
char p[30];
char num[30];
char re[1010];
int pipei(char *m,char *s)
{
    memset(p,-1,sizeof(p));
    memset(num,0,sizeof(num));
    int len1=strlen(m);
    int len2=strlen(s);
    if(len1!=len2){
        return 0;
    }
    else{
        for(int i=0;i<len1;i++){

            int c=s[i]-'a';
            if(p[c]!=-1){
                if(p[c]==d[i]-'a'){
                    continue;
                }
                else{
                    return 0;
                }
            }
            p[c]=d[i]-'a';
            int b=d[i]-'a';
            num[b]++;
            if(num[b]>1){
                return 0;
            }
        }
    }
    if(len1==25){
        int last;
        for(int i=0;i<26;i++){
            if(!num[i]){
                last=i;
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(p[i]==-1){
                p[i]=last;
            }
        }
    }
    return 1;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(s,0,sizeof(s));
        memset(re,0,sizeof(re));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]);
        }
        scanf("%s",d);
        scanf("%s",x);
        int flag=0;


        int len =strlen(x);
        for(int i=1;i<=n;i++){
            if(pipei(d,s[i])){
                flag=1;
                for(int i=0;i<len;i++){
                    int c=x[i]-'a';
                    if(p[c]!=-1){
                        if(re[i]=='?')
                            continue;
                        else if(re[i]==0){
                            re[i]=p[c]+'a';
                        }
                        else if(re[i]-'a'!=p[c]){
                            re[i]='?';
                        }

                    }
                    else{
                        re[i]='?';
                    }
                }
                re[len]='\0';
            }
        }
        if(flag){
            if(strcmp(re,"")!=0)
                printf("%s\n",re);
            else
                printf("IMPOSSIBLE\n");
        }
        else{
            printf("IMPOSSIBLE\n");
        }

    }
}

