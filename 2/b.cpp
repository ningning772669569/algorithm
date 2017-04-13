#include "algorithm"
#include "cstdio"
#include "iostream"
#include "cstring"
#define MAX 12
using namespace std;
int N;
int num;
int have[MAX];
int pos[MAX];
int re[MAX];
void search(int n)
{
        if(n==N+1){
            num++;
            return ;
        }
        for(int i=1;i<=N;i++){
            if(have[i]) continue;
            int flag=1;
            for(int j=1;j<n;j++){
                if(abs(pos[j]-i)==abs(n-j))
                    flag=0;
            }
            if(!flag)
                continue;
            have[i]=1;
            pos[n]=i;
            search(n+1);
            have[i]=0;
        }

}
int main ()
{
    memset(re,-1,sizeof(re));
    while(1){
        cin >> N;
        if(N==0)    break;
        if(re[N]!=-1) {printf("%d\n",re[N]);continue;}
        num=0;
        memset(have,0,sizeof(have));
        memset(pos,0,sizeof(pos));
        search(1);
        re[N]=num;
        printf("%d\n",num);

    }
    return 0;
}
