#include "cstdio"
#include "algorithm"
using namespace std;
int num[3];

int main ()
{
    int result;
    while(scanf("%d %d %d",&num[0],&num[1],&num[2])!=EOF){
        sort(num,num+3);

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

