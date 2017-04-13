#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n,b,c;
int num[150];
int main ()
{
    while(scanf("%d%d%d",&n,&b,&c)==3){
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        int re=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((abs(num[i]-num[j])%b) == c)
                    re++;
            }
        }
        cout<<re<<endl;
    }
    return 0;
}
