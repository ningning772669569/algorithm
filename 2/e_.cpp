#include "algorithm"
#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
char s[20];
int num;
int len;
long long N;
void dfs(int pos,long long ans)
{
    if(pos==len){
        if(ans==N){
            num++;
        }
        return ;
    }
    long long k=0;
    for(int i=pos;i<len;i++){
        k=k*10+s[i]-'0';
        dfs(i+1,ans+k);
        if(pos!=0)
        dfs(i+1,ans-k);
    }
}
int main ()
{
    while(~scanf("%s",s)){
        scanf("%ld",&N);
        num=0;
        len=strlen(s);
        dfs(0,0);
        printf("%d\n",num);
    }
    return 0;
}
/**
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int len;
char s[15];
ll n,ans;

void dfs(int sum,int id)
{
    if(id==len)
    {
        if(sum==n)
            ans++;
        return;
    }
    ll tmp=0;
    for(int i=id;i<len;i++)
    {
        tmp=tmp*10+(s[i]-'0');
        dfs(sum+tmp,i+1);
        if(id)
            dfs(sum-tmp,i+1);
    }
}
int main()
{
   while(~scanf("%s%I64d",s,&n))
   {
       ans=0;
       len=strlen(s);
       dfs(0,0);
       printf("%I64d\n",ans);
   }
}
*/
