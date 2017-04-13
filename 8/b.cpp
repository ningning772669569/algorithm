#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "bitset"
#define MAX 10000000
using namespace std;
int  n,k;
int Max;
bitset<1000000000> bit;
int main ()
{
    while (scanf("%d %d",&n,&k)==2){
        Max=0;
        int tep;
        memset(bit,0,sizeof(bit));
        for(int i=1;i<n;i++){
            scanf("%d",&tep);
            if(tep>Max)
                Max=tep;
        }
    }
}
