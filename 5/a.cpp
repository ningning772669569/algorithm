#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#define MAXLEN 1000002
using namespace std;
int N;
int Max;
int alloc;
int tire[MAXLEN][26];



void _insert(char *s)
{
    int l=0;
    int len=strlen(s),cur=0;
    for (int i=0;i<len;i++)
    {
        if (tire[cur][s[i]-'a']==-1) tire[cur][s[i]-'a']=++alloc;
        else l++;

        cur=tire[cur][s[i]-'a'];

    }
    Max=max(l,Max);
}
int main ()
{
    while (scanf("%d",&N)!=EOF){
        alloc=0;
        char s[60];
        Max=0;

        memset(tire,-1,sizeof(tire));

        for(int i=1;i<=N;i++){
            cin >> s;
            _insert(s);
        }
        printf("%d\n",Max);

    }
    return 0;
}
