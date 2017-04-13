#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstring"
using namespace std;
int na,nb;
int n;
int a,b,c,d;
int main ()
{
    scanf("%d%d",&na,&nb);
    cin >>n;
    int ta=na;
    int tb=nb;
    for(int i=1;i<=n&&(ta>=0)&&(tb>=0);i++){
        cin >>a>>b>>c>>d;
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if (b==d)
            continue;
        if((b==a+c)&&(d!=a+c)){
            ta--;
        }
        if((b!=a+c)&&(d==a+c)){
            tb--;
        }
    }
    if(ta<0){
        cout<<"A"<<endl;
        cout<<nb-tb;
        }
    else{
        cout<<"B"<<endl;
        cout<<na-ta;
        }
    return 0;
}
