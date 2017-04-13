#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "vector"
#include "math.h"
using namespace std;
int p,e ,i,d;
int main ()
{
    int t=1;
    while(1){
        scanf("%d %d %d %d",&p,&e,&i,&d);
        if(p==-1&&e==-1&&i==-1&&d==-1)
            break;


        for(int j=d+1;j<=21253+d;j++){
            if((j-p)%23==0){
                if((j-e)%28==0){
                    if((j-i)%33==0){
                        printf("Case %d: the next triple peak occurs in %d days.\n",t,j-d);
                        break;
                    }
                }
            }
        }
        t++;
    }
    return 0;
}
