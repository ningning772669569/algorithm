#include "cstdio"
#include "algorithm"
using namespace std;
int main ()
{
    int MAX=2000,i,j,mycount=0;
    int A[MAX];
    int B[MAX];
    int m,n;
    while(scanf("%d %d",&n,&m)==2&&n&&m){
        for(i=0;i<n;i++){
            scanf("%d",A+i);
        }
        for(j=0;j<m;j++){
            scanf("%d",B+j);
        }
        sort(A,A+n);
        sort(B,B+m);
        i=0;j=0;
        while(i<n&&j<m){
            //while(j<m){
                if(A[i]<=B[j]){
                    //j++;
                    //i++;
                    mycount=B[j]+mycount;
                    i++;j++;
                    //break;
                }
                else{
                    j++;
                }
            //}
        }
        if(i>=n&&j<=m){
            printf("%d",mycount);
        }
        else{
            printf("no way");
        }
    }
    return 0;
}
