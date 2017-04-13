#include "stdio.h"
#include "stdlib.h"

int main ()
{
    int depth,num;
    int i;
    int pos;
    while (scanf("%d %d",&depth,&num)==2){///scanf 是返回的读到的数字的个数，所以这样可以一直读下去
        pos=1;
        for(i=0;i<depth-1;i++){
            if(num%2){
                pos=pos*2;
                num=(num+1)/2;
            }
            else{
                pos=pos*2+1;
                num=num/2;
            }
        }
        printf(" %d\n",pos);
    }
    return 0;
}
