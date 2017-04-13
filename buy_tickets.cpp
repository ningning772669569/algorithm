#include "algorithm"
#include "cstring"
#include "cstdio"
using namespace std;
int num[300];
void mul(int n);
void fac (int n);
void div(int n);
void show();
int main ()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int t=1;
    while(m||n){
        memset(num,0,sizeof(num));
        num[0]=1;
        fac(m+n);
        //show();
        mul(m-n+1);
        div(m+1);
        printf("Test #%d\n",t);
        show();
        t++;
        scanf("%d %d",&m,&n);

    }
    return 0;
}
void mul(int n)
{
    int i;
    int c=0;
    for(i=0;i<300;i++){
        num[i]=num[i]*n+c;
        c=num[i]/10;
        num[i]=num[i]%10;
    }
}
void fac (int n)
{
    for(int i=2;i<=n;i++)
        mul(i);
}
void div(int n)
{
    int i;
    int b=0;
    for(i=300-1;i>=0;i--){
        int a=num[i]+b*10;
        num[i]=a/n;
        b=a%n;
    }
}
void show()
{
    int i=300-1;
    while(i>=0){
        if(num[i]){
            break;
        }
        i--;
    }
    for(;i>=0;i--){
        printf("%d",num[i]);
    }
    printf("\n");
}
