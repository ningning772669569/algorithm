#include "algorithm"
#include "cstdio"
#include "string"
using namespace std;
int num[100000];
int main ()
{
    int T;
    int i;
    int N;
    int j;
    int tep;
    int dif_num;
    scanf ("%d",&T);
    int result[T+1];

    for(i=1;i<=T;i++){
        scanf("%d",&N);
        dif_num=N;
        for(j=0;j<100000;j++){
            num[j]=0;
        }
        for(j=1;j<=N;j++){
                scanf("%d",&tep);
                if(num[tep])
                    dif_num--;
                num[tep]++;

        }
        result[i]=dif_num*(dif_num-1)*(dif_num-2)/6;

    }
    for(i=1;i<=T;i++)
        printf("%d\n",result[i]);
    return 0;
}
