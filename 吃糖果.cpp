#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=1000010;
LL sum;
int N;
LL num[maxn];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        sum=0;
        for(int i=1;i<=N;i++){
            scanf("%I64d",&num[i]);
            sum+=num[i];
        }
        bool flag=true;
        for(int i=1;i<=N;i++){
            if(2*num[i]-1>sum){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<std::endl;
        }
        else {
            cout<<"No"<<std::endl;
        }
    }
    return 0;
}
