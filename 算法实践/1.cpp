#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=50009;
int f[maxn];
int r[maxn];
int N,K;
int find (int u)
{
    if(u==f[u])
        return f[u];
    int tep=f[u];
    f[u]=find(f[u]);
    r[u]=(r[u]+r[tep])%3;
    return f[u];
}

int main()
{
    freopen("in.dat","r",stdin);
    scanf("%d%d",&N,&K);
        for(int i=1;i<=N;i++){
            r[i]=0;
            f[i]=i;
        }
        int re=0;
        for(int k=1;k<=K;k++){
            //cout<<re<<endl;
            int d,a,b;
            scanf("%d%d%d",&d,&a,&b);
            if(a>N || b>N){
                re++;
                continue;
            }
            if(d==2 && a==b){
                re++;
                continue;

            }
            //cout<<k<<endl;
            int fa,fb;
            fa=find(a);
            fb=find(b);
            //cout<<fa<<" "<<fb<<" "<<r[a]<<" "<<r[b]<<endl;
            if(fa==fb){
                //cout<<k<<endl;
                if(d==1){
                    //cout<<"!!!!!"<<endl;
                    //cout<<r[a]<<r[b]<<endl;
                    if(r[a]!=r[b]){
                        re++;
                        continue;
                    }
                }
                else{
                    if(r[a]!=((r[b]+1)%3)){
                        re++;
                        continue;
                    }
                }
            }
            if(fa!=fb){
                f[fa]=fb;
                r[fa]=(d-1-r[a]+r[b]+3)%3;
            }
            //cout<<f[fa]<<" "<<f[fb]<<" "<<r[a]<<" "<<r[b]<<endl;
        }
        cout<<re<<endl;

    return 0;
}
