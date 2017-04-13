#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=100010;

char s[maxn];
char t[maxn];
int vis[maxn];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        scanf("%s",s);
        scanf("%s",t);
        //int lens,lent;
        int lent=strlen(t);
        int lens=strlen(s);
        if((s[0]!=t[0])||(lens>lent)){
            printf("No\n");
                continue;
        }
        int post=0;
        int poss=0;
        while(poss<lens&&post<lent){
            while(s[poss]==t[post]){
                vis[post]=1;
                poss++;
                post++;

            }
            post++;
        }
        int flag=1;
        for(int i=0;i<lent;i++){
            //cout<<vis[i];
            if(!vis[i]){
                if(t[i]==t[i-1]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
