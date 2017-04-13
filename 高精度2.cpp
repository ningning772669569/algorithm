#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
const int Max=100;
int num[Max];
int main ()
{
    int n;
    cin >>n;
    memset(num,0,sizeof(num));
    num[0]=1;
    int c;
    for(int i=2;i<=n;i++){
        c=0;
        for(int j=0;j<Max;j++){
            num[j]=num[j]*i+c;
            c=num[j]/10;
            num[j]=num[j]%10;
        }
    }
    int i;
    for(i=Max-1;i>=0;i--){
        if(num[i])
             break;
    }
    for(;i>=0;i--)
        printf("%d",num[i]);
    return 0;
}
