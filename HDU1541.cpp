#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=36000;
int c[maxn];
int re[maxn];
int N;
int lowbit(int k)
{
    return (k&(-k));
}
void update(int pos,int num)
{
    while(pos<maxn){
        c[pos]+=num;
        pos+=lowbit(pos);
    }
}
int sum(int pos)
{
    int s=0;
    while(pos>=1){
        s+=c[pos];
        pos-=lowbit(pos);
    }
    return s;
}
int main ()
{
    while(scanf("%d",&N)!=EOF){
        //cout<<"&&&"<<N<<endl;
        memset(re,0,sizeof(re));
        memset(c,0,sizeof(c));
        for(int i=1;i<=N;i++){
            int pos;
            int a;
            scanf("%d %d",&pos,&a);
            int t=sum(pos+1);
            //cout<<t<<" " <<pos<<endl;
            re[t]++;
            update(pos+1,1);
        }
        for(int i=0;i<N;i++)
            printf("%d\n",re[i]);
    }
    return 0;
}
