#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "stack"
using namespace std;
char s[220];
stack<double> num;
stack<char> symbol;
int ans;
int getnum(int lasti,int i)
{
    int a=0;
    for(int j=lasti+1;j<i;j++){
        a=a*10+s[j]-'0';
    }
    return a;
}

int main ()
{
    while(1){




        gets(s);
        while(!num.empty()){
            num.pop();
        }
        while(!symbol.empty())
            symbol.pop();
        if(strcmp(s,"0")==0){
            break;
        }
        int lasti=-1;
        int i=0;
        int len=strlen(s);
        while(i<len){
            while(i<len&&(s[i]!=' '))i++;
            if(s[lasti+1]>='0'&&s[lasti+1]<='9'){
                double tep=(double)getnum(lasti,i);
                num.push(tep);
            }
            else{
                if(s[lasti+1]=='-'||s[lasti+1]=='+'){
                    symbol.push(s[lasti+1]);
                }
                else if(s[lasti+1]=='/'){
                    lasti=i;i++;
                    while(i<len&&(s[i]!=' '))i++;
                    double tep=(double)getnum(lasti,i);
                    double tep2=num.top();
                    num.pop();
                    double tep3=tep2/tep;
                    num.push(tep3);
                }
                else{
                    lasti=i;i++;
                    while(i<len&&(s[i]!=' ')) i++;
                    double tep=(double)getnum(lasti,i);
                    double tep2=num.top();
                    num.pop();
                    double tep3=tep*tep2;
                    num.push(tep3);
                }
            }
            lasti=i;i++;
        }
        while(!symbol.empty()){
            char a=symbol.top();
            symbol.pop();
            double tep1,tep2,tep3;
            tep1=num.top();num.pop();
            tep2=num.top();num.pop();
            if(a=='+')
                tep3=tep1+tep2;
            else
                tep3=tep2-tep1;

            num.push(tep3);
        }
        printf("%.2lf\n",num.top());
        num.pop();

    }
    return 0;
}

