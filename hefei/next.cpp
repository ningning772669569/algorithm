#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
int b[40];
LL two[31];
int main ()
{
    two[0]=1;
    for(int i=1;i<=33;i++){
        two[i]=2*two[i-1];
    }
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(b,0,sizeof(b));
        LL D;
        int s1,s2;
        int pos=0;
        int num=0;
        scanf("%I64d %d %d",&D,&s1,&s2);
        LL tepd=D;
        while(D){
            b[pos]=D&1;
            num+=b[pos];
            pos++;
            D/=2;
        }
        int flag=1;
        if(num<s2){
            flag=0;
        }
        pos=0;
        int num2=0;

        while(b[pos] || flag) {
            num2+=b[pos];
            tepd-=(b[pos]*two[pos]);
            if(b[pos]){flag=0;}
            pos++;
        }
        tepd+=two[pos];
        int num3=num-num2+1;
        int tt=0;
        while(num3<s1){
            tepd+=two[tt];
            tt++;
            num3++;
        }
        printf("Case #%d: %I64d\n",t,tepd);
    }

}
