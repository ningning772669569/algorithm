#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
#include "math.h"
#define eps (1e-5)
#define MAX 20

using namespace std;

int N;
int posx[MAX];
int posy[MAX];
bool vis[10000];
map<long long,int> times;
double dis(int i,int j)
{
    return sqrt((posx[i]-posx[j])*(posx[i]-posx[j])+(posy[i]-posy[j])*(posy[i]-posy[j]));
}
bool have_vis(int i,int j,int k)
{
    if(i<j)
        swap(i,j);
    if(i<k)
        swap(i,k);
    if(j<k)
        swap(k,j);
    int num=i*18*18+j*18+k;
    if(vis[num])
        return true;
    else{
        vis[num]=true;
        return false;
    }
}
long long get_num(int i,int j,int k)
{
    double l1=dis(i,j);
    double l2=dis(j,k);
    double l3=dis(k,i);
    double a1=acos((l1*l1+l2*l2-l3*l3)/(2*l1*l2));
    double a2=acos((l2*l2+l3*l3-l1*l1)/(2*l2*l3));
    double a3=acos((l1*l1+l3*l3-l2*l2)/(2*l1*l3));
    if(a1<eps||a2<eps||a3<eps){
        return 0;
    }
    if(a1<a2)
        swap(a1,a2);
    if(a1<a3)
        swap(a1,a3);
    if(a2<a3)
        swap(a2,a3);
    long long bianhao=a1*(1e10)+a2*(1e5);///a3已经定了
    return bianhao;
}
int main ()
{
    while(scanf("%d",&N)!=EOF&&N){

        times.clear();
        memset(vis,0,sizeof(vis));
        if(N==1){
            printf("1\n");
            continue;
        }
        for(int i=1;i<=N;i++){
            scanf("%d %d",&posx[i],&posy[i]);
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(j==i)
                    continue;
                for(int k=1;k<=N;k++){
                    if(k==i||k==j)
                        continue;
                    if(have_vis(i,k,j))
                        continue;

                    long long num=get_num(i,j,k);
                    if(num!=0)
                    times[num]++;
                }
            }
        }
        int re=0;
        for(map<long long,int>::const_iterator iter=times.begin();iter!=times.end();iter++){
            if(re<iter->second)
                re=iter->second;
        }
        printf("%d\n",re);

    }
    return 0;
}
