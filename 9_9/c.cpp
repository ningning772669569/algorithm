#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
typedef long long LL;
const int maxn=1010;
int n;
LL num[maxn];
int main ()
{
    while(scanf("%d",&n)!=EOF){
        double sum=0;
        int s=0;
        double aver;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&num[i]);
            sum+=num[i];
        }
        aver=(sum/n)*1.0;
        for(int i=1;i<=n;i++){
            if(num[i]>aver)
                s++;
        }
        printf("%d\n",s);
    }

}
