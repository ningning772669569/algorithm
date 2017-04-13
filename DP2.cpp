#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "cstdlib"
#define MAX 10
using namespace std;
int G[MAX][MAX];
int rec[MAX][2];
int d[MAX];
int N;
int dp(int);
int contain(int,int);
int main ()
{
    int n;
    scanf("%d",&n);
    N=n;
    memset(G,0,sizeof(G));
    for(int i=1;i<=N;i++){
        scanf("%d %d",&rec[i][0],&rec[i][1]);

    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            G[i][j]=contain(i,j);
        }
    }
    int the_max=0;
    int store;
    for(int i=1;i<=N;i++){
        //memset(d,0,sizeof(d));
        store=dp(i);
        d[i]=store;
        if(the_max<store)
            the_max=store;
        //the_max>?=dp(i);
    }
    cout <<the_max <<endl;
    return 0;
}
int contain (int i,int j)
{
    if(rec[i][0]>rec[j][0]&&rec[i][1]>rec[j][1])
        return 1;
    if(rec[i][0]>rec[j][1]&&rec[i][1]>rec[j][0])
        return 1;
    return 0;
}
int dp (int i)
{
    int store;
    if(d[i])
        return d[i];
    d[i]=1;
    for(int j=1;j<=N;j++){
        if(G[i][j]){
            store=dp(j)+1;
            if(d[i]<store)
                d[i]=store;
            //d[i] >? = dp(j)+1;
        }
    }
    return d[i];
}
