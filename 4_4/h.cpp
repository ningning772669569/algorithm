#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n,a,b,c;
int pos[30];
int num[10000];
int geshu;
int getnum(int a)
{
    int cha=abs(a);
    int re=cha*cha*a+b*cha+c;
    return re;
}
int gcd(int a,int b)
{
    return b==0? a: gcd(b,a%b);
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d %d %d",&n,&a,&b,&c);
        for(int i=1;i<=n;i++){
            int num;
            scanf("%d",&pos[i]);

        }
        geshu=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i=j){
                    continue;

                }
                geshu++;
                num[geshu]=pos[i]*pos[j];

            }
        }
        sort(num+1,num+1+geshu);
        long long sum=0;
        int tepnum=0;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=n-i;j++){
                ++tepnum;
                sum=sum+getnum(i)*num[tepnum];
            }
        }
        int yinshu=gcd(sum,10000);
        printf("%d/%d\n",sum/yinshu,10000/yinshu);

    }
}
