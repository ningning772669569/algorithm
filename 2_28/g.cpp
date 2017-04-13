#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL re;
LL MAX;
LL get(LL n)
{
    LL tep=1;
    while(n){
        tep=tep*(n%10);
        n/=10;
    }
    return tep;
}
int main ()
{
    LL a,b;
    while(scanf("%I64d %I64d",&a,&b)==2){
        LL dis=b-a;
        LL R;
        LL aa=a;
        LL bb=b;
        LL tep=dis;
        int num=0;
        while(tep){
            tep/=10;
            num++;
        }
        num--;
        LL MOD=1;
        for(int i=1;i<=num;i++)
            MOD*=10;
        ///cout<<num<<endl;
        int flag=0;
        ///cout<<MOD<<endl;
        if((b%MOD)==(MOD-1))
                flag=1;
        ///cout<<flag<<endl;
        for(int i=1;i<=num;i++)
        {
            a/=10;b/=10;
        }
        cout<<"%"<<num<<endl;
        LL tepa=a%100;
        LL tepb=b%100;
        re=tepa;
        MAX=get(tepa);
        LL up;
        if(flag)
            up=tepb;
        else
            up=tepb-1;
        ///cout<<up<<endl;
        for(LL i=tepa;i<=up;i++){
            LL cur=get(i);
            if(cur>MAX){
                re=i;
                MAX=cur;
            }
        }
        cout<<tepa<<"  "<<up<<endl;
        cout<<MAX<<endl;
        if(MAX!=0){
            a/=100;b/=100;
            if(a)
                cout<<a;
            if(re<10&&a>0)
                cout<<0;
            cout<<re;
            for(int i=1;i<=num;i++)
                cout<<9;
            cout<<endl;
        }
        else{
            tepb=bb%MOD;
            LL tMOD=MOD;
            LL tt=1;
            LL tepre=0;
            while(tepb){
                if(tepb%10)
                {
                    tepre+=tt*(tepb%10);
                }
                else{
                    if(tepb-10>0){
                        tepb=tepb-1;
                        tepre+=tt*(tepb%10);
                    }
                }
                tepb/=10;
                tt*=10;
            }
            cout<<bb/MOD;
            int j;
            int pre=1;
            for( j=1;j<=20;j++)
                if((pre=(pre*10))>tepre)
                    break;
            for(int i=1;i<j;i++)
                cout<<0;
            cout<<tepre<<endl;
        }
    }
    return 0;
}
