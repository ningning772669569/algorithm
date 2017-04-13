#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
int num[105];
int n;
int main ()
{
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(int i=1;i<=n;i++){
            char c;
            num[0]=0;
            scanf("%c",&c);
            if(c=='F')
                num[i]=3;
            else if(c=='A')
                num[i]=1;
            else
                num[i]=2;
        }

    }
}
