#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
int num[3];

int cmp ( const void *a , const void *b )
{
return *(int *)a - *(int *)b;
}


int main ()
{
    int result;
    while(scanf("%d %d %d",&num[0],&num[1],&num[2])){
        qsort(num,3,sizeof(num[0]),cmp);

        if(num[0]+num[1]>num[2]){
            result=num[2]*num[2]-num[0]*num[0]-num[1]*num[1];
            if(result==0){
                printf("Right\n");
            }
            else if(result>0){
                printf("Obtuse\n");
            }
            else{
                printf("Acute\n");
            }
        }
        else{
            printf("FAIL TO MAKE!\n");
        }
    }
    return 0;
}
