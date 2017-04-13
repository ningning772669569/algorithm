#include "algorithm"
#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
int num[50000];
int pos;
void show();
void cal (int n);
int main ()
{
    int n;
    while(scanf("%d",&n)){
        memset(num,0,sizeof(num));
        num[0]=1;
        cal(n);
        show();

    }
    return 0;
}
void cal (int n)
{
    int c=0;
    int i=2;
    for(;i<=n;i++){
        for(int j=0;j<50000;j++){
            num[j]=num[j]*i+c;
            c=num[j]/10;
            num[j]%=10;
        }
    }
}
void show()
{
    int pos=50000-1;
    while(pos>=0){
        if(num[pos]){
            break;
        }
        pos--;
    }
    for(int j=pos;j>=0;j--){
        printf("%d",num[j]);
    }
    printf("\n");
}
