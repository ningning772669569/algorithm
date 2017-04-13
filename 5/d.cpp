#include "cstring"
#include "cstdio"
#include "algorithm"
#include "iostream"
#define MAX 1100
#include "queue"
using namespace std;

int tire[MAX][26];
bool is_str[MAX][26];
char s[1000010];
int alloc;
void insert(char * s)
{
    int len=strlen(s);
    int cur=0;
    for(int i=1;i<len;i++){
        if(tire[cur][s[i]-'a'==-1)
            tire[cur][s[i]-'a']=alloc++;
        if(i==len-1)
            is_str[cur][s[i]-'a']=true;
        cur=tire[cur][s[i]-'a'];
    }
}
int getFail()
{
    queue<int> q;
    f[]
}
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        alloc=0;
        memset(tire,-1,sizeof(tire));
        memset(is_str,0,sizeof(is_str));
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        scanf("%s",s);


    }
}
