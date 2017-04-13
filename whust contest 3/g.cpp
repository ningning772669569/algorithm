#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n;
int main ()
{
    while(scanf("%d",&n)!=EOF){
        int sum1,sum2,sum3;
        sum1=sum2=sum3=0;
        getchar();
        for(int i=1;i<=n;i++){
            char c;
            char a[200];
            int pos=0;
            while((c=getchar())!='\n'){
                a[pos++]=c;
            }
            a[pos]='\0';

            if((strstr(a,"black")!=NULL)&&(strstr(a,"blue")!=NULL)){
                sum1++;
            }
            else if((strstr(a,"white")!=NULL)&&(strstr(a,"gold")!=NULL)){
                sum2++;
            }
            else{
                sum3++;
            }
        }
        double aa,bb,cc;
        aa=sum1*(1.0)/n;
        bb=sum2*(1.0)/n;
        cc=sum3*(1.0)/n;
        printf("%.5lf\n",aa*100);
        printf("%.5lf\n",bb*100);
        printf("%.5lf\n",cc*100);
    }
}
