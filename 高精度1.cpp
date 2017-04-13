#include "cstdio"
#include "cstring"
#include "algorithm"

using namespace std;

int main ()
{
    int a,b;
    int sum;
    int c;
    while(scanf("%d %d",&a,&b)){
        c=0;
        sum=0;
        while(a&&b){
            if(a%10+b%10+c>=10){
                sum++;
                c=1;
            }
            else{
                c=0;
            }
            a=a/10;
            b=b/10;
        }
        printf("%d\n",sum);
    }
    return 0;
}
