#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=510;
int N;
int cmp(int a,int b)
{
    return a>b;
}
int num[maxn];
int main (){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(num,0,sizeof(num));
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            num[a]+=b;
        }
        sort(num+1,num+maxn,cmp);
        int size=1;
        while(num[size]) size++;
        int sum=0;
        for(int i=1;i<size;i++){
            int times=num[i]/64;
            if(num[i]%64) times++;
            sum+=times;
        }
        int re=sum/36;
        if(sum%36) re++;
        printf("%d\n",re);
    }
}
