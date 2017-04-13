#include "cstdio"
#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
const int maxn=1000009;
int n;

int main ()
{

    while(scanf("%d",&n)!=EOF){
        if(n<2){
            printf("0\n");
            continue;
        }
        int sum=0;
        for(int i=1;i<=n/2;i++){
            int a=i,b=n-i;

                if(a!=b){
                    sum+=2;
                }
                else{
                    sum+=1;
                }
                int tep=a;
                a=b-a;
                b=tep;
                while(a>0){
                sum++;
                int tep=a;
                a=b-a;
                b=tep;
                }


        }
        printf("%d\n",sum);

    }
}
