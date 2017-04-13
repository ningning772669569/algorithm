#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int num[1000];
int partition(int * num,int l,int r)
{
    int posl=l;
    int posr=r;
    int store=num[posl];
    while(posl<posr){
        while(posl< posr && num[posr]>=store)
            posr--;
        if(posl<posr)
            num[posl]=num[posr];
        while(posl< posr &&num[posl] <= store)
            posl++;
        if(posl<posr)
            num[posr]=num[posl];
    }
    num[posl]=store;
    return posl;
}
void msort(int * num,int l,int r)
{
    //cout<<l<<" "<<r<<endl;
    int pos=partition(num,l,r);
    //cout<<pos<<endl;
    if(pos>l)
        msort(num,l,pos);
    if(pos<r)
        msort(num,pos+1,r);
}
int main ()
{
    int n;
    while(scanf("%d",&n)&& n){
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        msort(num,0,n-1);
        for(int i=0;i<n;i++){
            printf("%d ",num[i]);
        }
        cout<<endl;
    }
}
