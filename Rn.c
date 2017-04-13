#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
int main ()
{
    int N;
    int num=0;
    int result[101];
    int i;
    int high;
    double b;
    for(i=0;i<101;i++)
        result[i]=0;
    while(scanf("%d",&N)!=EOF){

        num++;
        high=sqrt(N);
        for(i=1;i<=high;i++){
            b=N-i*i;
            b=sqrt(b);
            if(b==floor(b))
                result[num]++;
        }
        result[num]=result[num]*4;
        b=sqrt(N*1.0);

    }
    for(i=1;i<=num;i++)
        printf("%d\n",result[i]);
    return 0;

}
