#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#define MAX 100
using namespace std;
struct node{
    int even,odd;
    int sum;
};
int num[10];
vector<struct node>dp[105];
int use[105];
int main ()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int pos=0;
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        for(int i=1;i<=9;i++){
            scanf("%d",&num[i]);
        }
        for(int i=1;i<=9;i++){
            for(int j=num[i];j>0;j--){
                pos++;
                use[pos]=i;
            }
        }
        struct node tep;
        tep.sum=use[1];
        tep.sum

    }
}
