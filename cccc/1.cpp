#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
char num[100];
int main ()
{
    scanf("%s",num);
    int len=strlen(num);
    int tnum=0;
    int nnum=0;
    for(int i=0;i<len;i++){
        if(num[i]=='2')
            tnum++;
        if(num[i]>='0' && num[i]<='9')
            nnum++;
    }
    double re =1.0;
    re=1.0*tnum/nnum;
    if(num[0]=='-')
        re=re*1.5;
    if((num[len-1]-'0')%2==0)
        re=re*2.0;
    re=re*100;
    printf("%.2lf",re);
    cout<<"%";
        //printf("%");
    return 0;
}
