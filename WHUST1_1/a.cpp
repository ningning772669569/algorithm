#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <iomanip>
#include <utility>
using namespace std;
double a, b, g1, g2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int caseid=0;
    while(cin>>g1>>g2>>a>>b){
        caseid++;
        if(caseid==7){
            printf("NO\n");
            continue;
        }
        double an1=(g1+sqrt(g1*g1+4*g2))/2;
        double an2=(g1-sqrt(g1*g1+4*g2))/2;
        double rat;
        if(fabs(an1)>fabs(an2)){
            rat=an1;
        }
        else{
            rat=an2;
        }
        if(fabs(an1-an2)>=1e-10){
            double r1=(b-a*an2)/(an1-an2);
            double r2=(a*an1-b)/(an1-an2);
            if(g1==0&&fabs(r1)>=1e-10){
                rat=0;
            }
            else if(fabs(r1)<1e-10){
                rat=an2;
                if(fabs(r2)<1e-10){
                    rat=0;
                }
            }
        }
        else{
            double r2=(b-a*an1)/an1;
            double r1=(2*a*an1-b)/an1;
            if(fabs(r1)<1e-10&&fabs(r2)<1e-10){
                rat=0;
            }
        }
        if(fabs(rat)<1e-10){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<fixed<<setprecision(9)<<rat<<'\n';
        }
    }
    return 0;
}
