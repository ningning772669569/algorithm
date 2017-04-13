#include "cstdio"
#include "cstring"
#include "iostream"

using namespace std;
char mytime[100];

int main ()
{
    scanf("%s",mytime);
    int h=mytime[0]-'0';
    h=h*10+mytime[1]-'0';

    int m=mytime[3]-'0';
    m=m*10+mytime[4]-'0';
    //cout<<h<<"  "<<m<<endl;
    if(h>=0 && h<12){
        cout<<"Only "<<mytime<<".  Too early to Dang.";
    }
    else if(h==12){
        if(m!=0){
            cout<<"Dang";
        }
        else{
            cout<<"Only "<<mytime<<".  Too early to Dang.";
        }
    }
    else{
        if(m!=0)
            h=h+1;
        //1212cout<<h<<endl;
        for(int i=1;i<=h-12;i++)
            cout<<"Dang";
    }
    return 0;
}
