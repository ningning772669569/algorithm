#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int main ()
{
    int x,y,w,n;
    while(scanf("%d %d %d %d",&x,&y,&w,&n)==4){
        int t=0;
        int num=1;
        int rt=0;
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        while(num<=n){
            if(rt+w<x){
                rt+=w;
                t+=w;
                num++;
            }
            else if(rt+w==x){
                rt=0;
                t+=w;
                num++;
                if(num==n){
                    printf("%d\n",t);
                    break;
                }
                t+=y;
                num++;
            }
            else{
                t+=x-rt+y;
                rt=0;
                num++;
            }
            if(num==n)
                printf("%d\n",t);

        }
    }
    return 0;
}
