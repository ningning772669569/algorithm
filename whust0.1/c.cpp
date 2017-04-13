#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
int n,p;
int main ()
{
    int T;
    scanf("%d",&T);
    char choice[20];
    for(int t=1;t<=T;t++){
        scanf("%d %s %d",&n,choice,&p);
        if(choice[0]=='e'){
            printf("%d\n",2*p-1);
        }
        else{
            printf("%d\n",2*p);
        }
    }
    return 0;
}
