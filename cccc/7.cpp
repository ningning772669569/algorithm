#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstring"
using namespace std;
char s[100010];
char ban[]="GPLT";
int num[4];
int main ()
{
    scanf("%s",s);
    int len=strlen(s);
    memset(num,0,sizeof(num));
    int sum=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++){
            if((s[i]==ban[j])||(s[i]==ban[j]-'A'+'a')){
                num[j]++;
                sum++;
            }
        }
    }
    int pos=0;
    for(int i=1;i<=sum;i++){
        while(num[pos]==0)
            pos=(pos+1)%4;
        cout<<ban[pos];
        num[pos]--;
        pos=(pos+1)%4;

    }
    return 0;
}
