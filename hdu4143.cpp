#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
int N;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        if(N==1)
        {
            printf("-1\n");
            continue;
        }
        int hi=sqrt(N);
        int re=-1;
        for(int i=1;i<=hi;i++){
            if(N%i == 0){
                if((N/i - i)%2==0 &&(N/i - i)!=0){
                    re=(N/i-i)/2;
                }
            }
        }
        printf("%d\n",re);
    }
}
