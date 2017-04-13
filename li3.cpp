#include "cstdio"
#include "algorithm"
using namespace std;
const int MAX=1000;
int A[MAX];
int B[MAX];
int main ()
{
    int n,x1,i;
    scanf("%d",&n);
    int sum=0,M;
    for(i=0;i<n;i++){
        scanf("%d",A+i);
        sum+=A[i];
    }
    M=sum/n;
    for(i=0;i<n;i++){
        B[i]=A[i]-M;
    }
    sort(B,B+n);
    if(n%2){
        x1=B[n/2];
    }
    else{
        x1=(B[n/2]+B[n/2-1])/2;
    }
    sum=0;
    for(i=1;i<n;i++){
        sum+=abs(x1-B[i]);
    }
    sum+=x1;
    printf("%d",sum);
}
