#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
int n,A,B,C,h,d,f,F;
char s[200];
int price[3];
int main ()
{
    while(scanf("%d %d %d %d %d")==5){
        long long Max=0;
        price[0]=h+d+f;
        price[1]=h+d+F*2;
        price[2]=3*h+3*d+2*F;
        for(int i=1;i<=n;i++){
            long long sum=0;
            getchar();
            gets(s);
            int len=strlen(s);
            for(int j=0;j<len;j++){
                sum=sum+price[s[j]-'A'];
            }
            if(Max<sum)
                Max=sum;
        }
        printf("%I64d\n",Max);
    }
    return 0;
}
