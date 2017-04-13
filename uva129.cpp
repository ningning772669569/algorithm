#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int N,L;
int size;
char s[100];
char re[100];
int cnt;
int caseid;
int check(int pos)
{
    if(pos==1){
        return 1;
    }
    int flag=1;
    for(int len=1;len<=pos/2;len++){
        int tepflag=0;
        for(int i=0;i<len;i++){
            if(s[pos-i]!=s[pos-len-i]){
                tepflag=1;
                break;
            }
        }
        if(!tepflag){
            flag=0;
            break;
        }
    }
    return flag;
}
void dfs (int pos)
{
    //cout<<cnt<<endl;
    for(int i=1;i<=L;i++){
        s[pos]=i;
        if(check(pos)&&cnt<=N){
            cnt++;
            if(cnt==N){
                for(size=1;size<=pos;size++){
                    re[size]=s[size]+'A'-1;
                }
                size--;
                return;
            }
            dfs(pos+1);
        }
    }


}
void show()
{

    for(int i=1;i<=size;i++){
        printf("%c",re[i]);
        if(i<size&&i==64)
        {
            printf("\n");
            continue;
        }
        if(i<size&&i%4==0)
            printf(" ");
    }

    printf("\n%d\n",size);


}
int main ()
{

    while(scanf("%d %d",&N,&L)==2){
        memset(s,0,sizeof(s));
        memset(re,0,sizeof(re));
        cnt=0;
        if(N==0){
            break;
        }
        caseid++;
        dfs(1);
        show();

    }
}
