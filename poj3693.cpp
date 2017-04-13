#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=100010;
int rank[maxn];
int wb[maxn];
int wv[maxn];
int wss[maxn];
int sa[maxn];
int height[maxn];
int r[maxn];
int d[maxn][20];
char s[maxn];
int len;
bool cmp(int * r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int * r,int * sa,int n,int m)
{
    int j,p;
    int *x=rank;
    int *y=wb;
    int * t;
    for(int i=0;i<m;i++)
        wss[i]=0;
    for(int i=0;i<n;i++)
        wss[x[i]=r[i]]++;
    for(int i=1;i<m;i++)
        wss[i]+=wss[i-1];
    for(int i=n-1;i>=0;i--){
        sa[--wss[x[i]]]=i;

    }
    int i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wss[i]=0;
        for(i=0;i<n;i++) wss[wv[i]]++;
        for(i=1;i<m;i++) wss[i]+=wss[i-1];
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return ;

}
void getHeight()
{
    int i,k=0;
    for(i=0;i<len;i++)
        rank[sa[i]]=i;
    for(i=0;i<len;i++){
        if(k) k--;
        int j=sa[rank[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rank[i]]=k;
    }

}
void initRMQ(int n)
{
    memset(d,0,sizeof(d));
    for(int i=0;i<len;i++)
        d[i][0]=height[i];
    for(int j=1;(1<<j)<=len;j++){
        for(int i=0;i+(1<<j)-1<len;i++){
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
}

int  RMQ(int from,int to)
{
    int k=0;
    while(1<<(k+1) <= to-from+1) k++;
    return min(d[from][k],d[to-(1<<k)+1][k]);

}
int main ()
{
    while(scanf("s",s)==1){
        if(s[0]=='#')
        break;
        len=strlen(s);
        for(int i=0;i<len;i++){
            r[i]=s[i]-'a'+1;
        }
        r[len-1]=0;
        da(r,sa,len,27);
        getHeight();
        initRMQ(len);
    }
    return 0;
}
