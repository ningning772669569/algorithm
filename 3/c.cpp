#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "vector"
#include "math.h"
#define MAX 100005
using namespace std;

vector<int> zhiyinshu[MAX];
int num[MAX];
long long geshu[MAX];
bool have[MAX];
long long s[MAX];

void deal (int n,int pos)
{
    int m=(int)sqrt(n+0.5);
    for(int i=2;i<=m;i++){
        if(n%i==0){
            zhiyinshu[pos].push_back(i);
            while(n%i==0) n=n/i;
        }
    }
    if(n>1){
        zhiyinshu[pos].push_back(n);
        }
}
void get_num(int i)
{
    long long sum=0;
    int _size=zhiyinshu[i].size();

    for(int j=1;j< (1<<_size);j++){

        int op=0;
        int tmp=1;
        for(int k=0;k<_size;k++){
            if((1<<k)&j){
                op++;
                tmp=tmp*zhiyinshu[i][k];
            }
        }
        if(op&1)
            sum+=s[tmp];
        else
            sum-=s[tmp];

    }

    geshu[i]=sum-1;
    if(sum==0) geshu[i]=0;
}
int main ()
{
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        int n;

        scanf("%d",&n);
        memset(s,0,sizeof(s));
        memset(geshu,0,sizeof(geshu));
        for(int i=1;i<=n;i++){
            zhiyinshu[i].clear();
            scanf("%d",&num[i]);
            have[num[i]]=true;
            deal(num[i],i);
        }

        for(int i=2;i<MAX;i++)
            for(int j=i;j<MAX;j+=i)
                if(have[j]) s[i]++;

        for(int i=1;i<=n;i++){
            get_num(i);
        }
        long long re=0;
        for(int i=1;i<=n;i++){
            re+=geshu[i]*(n-1-geshu[i]);

        }
        re/=2;

        printf("%ld\n",(n)*(n-1)*(n-2)/6-re);

    }
    return 0;
}
