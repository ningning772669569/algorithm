#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"

using namespace std;
string s;
string::size_type Size;
int num;
long long result;
void dfs(string::size_type pos,long long now)
{
    if(pos==Size){
        if(now==result)
            num++;
        return ;
    }
    long long k=0;
    for(string::size_type x=pos;x<Size;x++){
        k=k*10+(char)s[x]-'0';
        dfs(x+1,now+k);
        if(pos!=0)
            dfs(x+1,now-k);
    }
}
int main ()
{

    while(cin >> s){
        cin >> result;
        Size=s.size();
        num=0;

        dfs((string::size_type)0,0);
        printf("%d\n",num);
    }
}
