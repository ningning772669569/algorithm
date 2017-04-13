#include"stdio.h"
#include"string.h"
#include "stdbool.h"
#define MAX 30
int main ()
{
    char s[MAX];
    scanf("%s",s);
    int i,j;
    bool ok=true;
    int len=strlen(s);
    for (i=1;i<=len;i++){
        ok=true;
        if(len%i!=0)
            continue;
        for(j=i;j<len;j++){
            if(s[j]!=s[j%i]){
                ok=false;
                break;
            }
        }

        if(ok){
        printf("%d",i);
        break;
        }
    }
    return 0;
}
