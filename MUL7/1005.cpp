#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
int n,t;
int odd,even;
int pos;
void deal(int n)
{


    int tepodd=0,tepeven=0;
    int teppos;
    for(teppos=1;n>0;teppos++){
        int digtal=n%10;
        if(teppos%2){
            tepodd+=digtal;
        }
        else{
            tepeven+=digtal;
        }
        n/=10;
    }
    if(pos%2){
        if(teppos%2){
            int tep=tepodd;
            tepodd=tepeven;
            tepeven=tep;
        }
    }
    else{
        if(teppos%2==0){
        int tep=tepodd;
        tepodd=tepeven;
        tepeven=tep;}
    }
    odd+=tepodd;
    even+=tepeven;
    pos=pos+teppos-1;
}

int main ()
{
    int n,t;
    int caseid=0;
    while(scanf("%d %d",&n,&t)==2){
        if(n==-1&&t==-1){
            break;
        }
        caseid++;
        int tepn=n;
        odd=0;even=0;
        for(pos=1;tepn>0;pos++){
            int digtal=tepn%10;
            if(pos%2){
                odd+=digtal;
            }
            else{
                even+=digtal;
            }
            tepn/=10;
        }
        if(pos%2){
            int tep=odd;
            odd=even;
            even=tep;
        }

        for(int i=1;i<=t;i++){
            deal(odd+even);
        }
        if(abs(odd-even)%11==0){
            printf("Case #%d: Yes\n",caseid);
        }
        else{
            printf("Case #%d: No\n",caseid);
        }
    }
    return 0;
}
