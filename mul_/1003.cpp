#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn=100020;
LL n,m;
LL per;
LL sum[maxn];
bool vis[maxn];
vector<int> p[15];
LL psum[20];
int main ()
{
    int  T;
    scanf("%d",&T);
    sum[1]=1;
    for(int i=2;i<=100000;i++){
        sum[i]=sum[i-1]+i;
    }
    for(int t=1;t<=T;t++){
        scanf("%I64d %I64d",&n,&m);
        if(sum[n]%m!=0){
            printf("NO\n");
            continue;
        }
        if(2*m>n+1){
            printf("NO\n");
            continue;
        }
        per=sum[n]/m;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            p[i].clear();
        }
        bool flag=true;
        for(int i=1;i<=m;i++){
            int tepsum=0;
            bool tepflag=false;
            if(!flag)
                break;
            for(int j=n;j>=1;j--){
                if(vis[j])
                    continue;
                if(tepsum+j>per)
                    continue;
                tepsum+=j;
                p[i].push_back(j);
                if(tepsum==per){
                    tepflag=true;
                    break;
                }
            }

            if(tepflag){
                flag=true;
            }
            else{
                flag=false;
            }
        }
        if(flag){
            printf("YES\n");
            for(int i=1;i<=m;i++){
                for(vector<int>::size_type a=0;a<p[i].size();a++){
                    printf("%d",p[i][a]);
                    if(a<p[i].size()-1){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        else{
            printf("NO\n");
        }
    }
}
