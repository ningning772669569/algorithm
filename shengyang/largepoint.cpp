#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL num[5000006];
LL n,a,b;
LL ua[2];
LL da[2];
LL ui[2];
LL di[2];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%I64d %I64d %I64d",&n,&a,&b);
        for(LL i=1;i<=n;i++){
            scanf("%I64d",&num[i]);
        }


        LL uaa=-1;LL pos1;
        LL uai=10000000;LL pos2;
        for(LL i=1;i<=n;i++){
            if(num[i]>=0){
                if(num[i]>uaa){
                    pos1=i;
                    uaa=num[i];
                }
                if(num[i]<uai){
                    pos2=i;
                    uai=num[i];
                }
            }

        }
        ua[0]=pos1; ui[0]=pos2;
        uaa=-1; pos1=0;
        uai=10000000; pos2=0;
        for(LL i=1;i<=n;i++){
            if(num[i]>=0){
                if(num[i]>uaa&&i!=ua[0]){
                    pos1=i;
                    uaa=num[i];
                }
                if(num[i]<uai&&i!=ui[0]){
                    pos2=i;
                    uai=num[i];
                }
            }

        }
        ua[1]=pos1;ui[1]=pos2;
        ///*******************************************
        LL aa=-99999999; pos1=0;
        LL ai=1; pos2=0;
        for(LL i=1;i<=n;i++){
            if(num[i]<0){
                if(num[i]>aa){
                    pos1=i;
                    aa=num[i];
                }
                if(num[i]<ai){
                    pos2=i;
                    ai=num[i];
                }
            }

        }
        da[0]=pos1; di[0]=pos2;
        aa=-99999999;;pos1=0;
        ai=1; pos2=0;
        for(LL i=1;i<=n;i++){
            if(num[i]<0){
                if(num[i]>aa&&i!=da[0]){
                    pos1=i;
                    aa=num[i];
                }
                if(num[i]<ai&&i!=di[0]){
                    pos2=i;
                    ai=num[i];
                }
            }

        }
        da[1]=pos1;di[1]=pos2;




        ///*****************************************
        LL MAX=-9999999999;
        if(a>0&&b>0){
            MAX=max(a*num[ua[0]]*num[ua[0]]+b*num[ua[1]],MAX);
            MAX=max(a*num[ua[1]]*num[ua[1]]+b*num[ua[0]],MAX);
            MAX=max(a*num[di[0]]*num[di[0]]+b*num[ua[0]],MAX);
        }
        else if(a>0 &&b<0){
            MAX=max(a*num[ua[0]]*num[ua[0]]+b*num[di[0]],MAX);
            MAX=max(a*num[di[0]]*num[di[0]]+b*num[di[1]],MAX);
            MAX=max(a*num[di[1]]*num[di[1]]+b*num[di[0]],MAX);
        }
        else if(a<0&&b>0){
            MAX=max(a*num[ui[0]]*num[ui[0]]+b*num[ua[0]],MAX);
            MAX=max(a*num[da[0]]*num[da[0]]+b*num[ua[0]],MAX);

        }
        else if(a<0&&b<0){
            MAX=max(a*num[ui[0]]*num[ui[0]]+b*num[di[0]],MAX);
            MAX=max(a*num[da[0]]*num[da[0]]+b*num[di[0]],MAX);

        }
        else if(a==0){
            if(b>=0)
                MAX=max(b*num[ua[0]],MAX);
            else
                MAX=max(b*num[di[0]],MAX);
        }
        else if(b==0){
            if(a>=0){
                MAX=max(a*num[ua[0]]*num[ua[0]],MAX);
                MAX=max(a*num[di[0]]*num[di[0]],MAX);
            }
            else {
                MAX=max(a*num[ui[0]]*num[ui[0]],MAX);
                MAX=max(a*num[da[0]]*num[da[0]],MAX);
            }
        }
        printf("Case #%d: %I64d\n",t,MAX);

    }
}
