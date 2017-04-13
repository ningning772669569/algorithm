#include "cstdio"
#include "algorithm"
#include "math.h"
using namespace std;
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
    int state=1;
    char number[100];
    while(number=getline()){

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
        state--;
        //if(b==floor(b))
            //result[num]=result[num]+2;
    }
    for(i=1;i<=num;i++)
        printf("%d\n",result[i]);
    return 0;

}
