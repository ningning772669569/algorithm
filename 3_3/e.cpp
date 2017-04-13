#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
int n,k,m;
int kinds[1002];
int times;
int main ()
{
    while(scanf("%d %d %d",&n,&m,&k)==3){
        times=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&kinds[i]);
        }
        for(int i=1;i<=n;i++){
            if(kinds[i]==1){
                if(m>0)
                    m--;
                else{
                    times++;

                }

            }
            else{
                if(k>0)
                    k--;
                else{
                    if(m>0){
                        m--;
                    }
                    else{
                        times++;
                    }
                }
            }
        }
        printf("%d\n",times);
    }
}
