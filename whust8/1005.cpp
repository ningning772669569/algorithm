#include "cstdio"
#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;
int yuansu[]={1,2,3,5,4,6,8,7,9,10,11,13,12,14,16,15,17,18,35,36,53,54,85,86};
int main ()
{
    int u,v;
    while(scanf("%d %d",&u,&v)==2){
        if(abs(u-v)<8){
            int * f,*s;
            f=find(yuansu,yuansu+24,u);
            s=find(yuansu,yuansu+24,v);
            if(f>s){
                printf("FIRST BIGGER\n");
            }
            else{
                printf("SECOND BIGGER\n");
            }
        }
        else{
            if(u<v){
                printf("FIRST BIGGER\n");
            }
            else{
                printf("SECOND BIGGER\n");
            }
        }
    }

    return 0;
}
