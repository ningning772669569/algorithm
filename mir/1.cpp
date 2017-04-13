#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long LL;
LL num[1100];
LL N,P,W,H;
int main ()
{
    int T;
    cin >> T;
    for(int caseid=1;caseid<=T;caseid++){
        cin >>N>>P>>W>>H;
        for(int i=1;i<=N;i++){
            scanf("%I64d",&num[i]);
        }
        LL sum=0;
        for(int i=1;i<=N;i++)
            sum+=num[i];
        LL maxsize=(P*W*H)/sum;

        maxsize=sqrt(maxsize)+1;
        //cout<<maxsize<<endl;
        while(maxsize>0){
            int hsum=0;
            for(int i=1;i<=N;i++){
                LL hnum=W/maxsize;
                hsum+=num[i]/hnum;
                if(num[i]%hnum!=0)
                    hsum++;
            }
            //cout<<"!!"<<hsum<<endl;
            if(hsum<=((H/maxsize)*P)){
                cout<<maxsize<<endl;
                break;
            }
            maxsize--;
        }
    }
    return 0;
}
