#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"
#include "set"
#include "map"
#include "queue"
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int N;
int num[4];
int sum[4];
int w[20010];

bool cmp(int a,int b)
{
    return a>b;
}

int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=N;i++){
            scanf("%d",&w[i]);
        }
        sort(w+1,w+1+N,cmp);
        //cout<<"!!!!!"<<endl;
        for(int i=1;i<=N;i++){
            int MAX=0x3fffffff;
            //cout<<MAX<<endl;
            int choice=0;
            for(int k=1;k<=3;k++){

                int tep=(sum[k]+w[i])*(num[k]+1);
                //cout<<tep<<endl;
                if(tep<MAX){
                    choice=k;
                    MAX=tep;
                }
            }
            sum[choice]+=w[i];
            num[choice]++;
            //cout<<"!!!!"<<endl;
        }
        LL re=0;
        for(int k=1;k<=3;k++){
            re+=num[k]*sum[k];
        }
        cout<<re<<endl;
    }
}
