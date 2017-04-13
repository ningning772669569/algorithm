#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL num[110000];
LL sum[110000];
LL sum2[110000];
LL n,m;
int main ()
{
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        sort(num+1,num+1+n);
        LL re=0x3f3f3f3f;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+num[i];
        }
        for(int i=1;i+m-1<=n;i++){
            LL s=0;
            int flag=0;
            for(int j=i;j<=i+m-1;j++){
                s+=sum[i+m-1]-sum[j]-((i+m-1-j)*num[j]);
                if(s>=re){
                    flag=1;
                    break;
                }
            }
            if(!flag)
                re=min(s,re);
        }
        cout<<re<<endl;
    }
    return 0;
}
