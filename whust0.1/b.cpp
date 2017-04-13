#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int sum;
int pos[40]={0,1,2,10,11,12,20,21,22,30,31,32,40,41,50,51};
void check(int h,int m,int s)
{
    if((m==0)||(m==11)||(m==22)||(m==33)||(m==44)||(m==55)){
        if((h%10)!=(s/10))
            return;
        if((h/10)!=(s%10))
            return;
        sum++;
    }
}
bool small(int nh,int nm,int ns,int eh,int em,int es)
{
    if(nh<eh)
        return true;
    if(nh<=eh&&nm<em)
        return true;
    if(nh<=eh&&nm<=em&&ns<=es)
        return true;
    return false;
}
int main ()
{
    int q;
    scanf("%d",&q);
    while(q--){
        getchar();
        int sh,sm,ss,eh,em,es;
        char c,s;
        c=getchar();s=getchar();sh=(c-'0')*10+(s-'0');
        getchar();
        c=getchar();s=getchar();sm=(c-'0')*10+(s-'0');
        getchar();
        c=getchar();s=getchar();ss=(c-'0')*10+(s-'0');
        getchar();
        c=getchar();s=getchar();eh=(c-'0')*10+(s-'0');
        getchar();
        c=getchar();s=getchar();em=(c-'0')*10+(s-'0');
        getchar();
        c=getchar();s=getchar();es=(c-'0')*10+(s-'0');
        sum=0;
        int nh,nm,ns;
        nh=sh;nm=sm;ns=ss;

        while((nm%10)!=(nm)/10){

            if(nm>55){
                nm=0;
                nh++;
                break;
            }
            nm++;
        }
        int i;
        if(nm!=sm)
            i=0;
        else{
            i=0;
            while(pos[i]<ss){
                i++;
                if(i==16){
                    i=0;
                    nm+=11;
                    if(nm>60){
                        nm=0;
                        nh++;
                    }
                    break;
                }
            }
        }
        ns=pos[i];
        while(small(nh,nm,ns,eh,em,es)){
            check(nh,nm,ns);

            i++;
            if(i==16){
                i=0;
                nm=nm+11;
                if(nm>60){
                    nm=0;
                    nh++;
                }
            }
            ns=pos[i];

        }
        printf("%d\n",sum);
    }
}
