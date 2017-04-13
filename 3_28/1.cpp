#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;
int m,n;
char str[300009];
int main ()
{
    while(scanf("%d%d",&m,&n)==2){
    memset(str,0,sizeof(str));
    scanf("%s",str+1);
    int re=0;
    int pos=1;
    while(pos<=m){
        if(str[pos]=='.'){
            int lastpos=pos;
            while(pos<=m && str[pos]=='.')
                pos++;
            if(pos-lastpos>=2)
                re+=pos-lastpos-1;
        }
        pos++;
    }
    for(int i=1;i<=n;i++){
        char c;
        cin >> pos>>c;
        if(str[pos]!='.'&& c=='.'){
            if(pos>1 && str[pos-1]=='.' && pos<n && str[pos+1]=='.'){
                re+=2;
            }
            else if((pos>1 && str[pos-1]=='.')||(pos<m && str[pos+1]=='.')){
                re+=1;
            }
        }
        else if(str[pos]=='.' && c!='.'){
            if(pos>1 && str[pos-1]=='.'&&pos<m && str[pos+1]=='.'){
                re-=2;
            }
            else if((pos>1 && str[pos-1]=='.') || (pos<m && str[pos+1]=='.')){
                re-=1;
            }
        }
        str[pos]=c;
        cout<<re<<endl;;
    }
    }
    return 0;
}
