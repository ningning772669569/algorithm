#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> g[500];
int vis[200];
int N;
int result;
int have(int u,int son)
{
    vis[u]=1;
    if (u==son)
        return 1;
    int re=0;
    for(unsigned int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v])
            continue;
        re=re||have(v,son);
    }
    return re;

}
void dfs(int u,int fa,int son)
{
    vis[u]=1;
    if(u==fa){
        result = have(fa,son);
    }
    for(unsigned int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v])
            continue;
        dfs(v,fa,son);
    }
}
int f(int fa,int son)
{
    memset(vis,0,sizeof(vis));
    result=0;
    dfs(1,fa,son);
    //result=0;
    return result;
}
int main ()
{
    int T;
    cin >>T;
    while(T--){
        cin >>N;
        for(int i=0;i<=N;i++)
            g[i].clear();
        for(int i=1;i<N;i++){
            int l,r;
            cin >>l>>r;
            g[l].push_back(r);
            g[r].push_back(l);
        }
        cin >>N;
        int num[110];
        for(int i=1;i<=N;i++)
            scanf("%d",&num[i]);

        int flag=1;
        for(int i=N;i>=1;i--){
            for(int j=i-1;j>=1;j--){
                if(f(num[i],num[j])){
                    //cout<<"fa:"<<num[i]<<"   son"<<num[j]<<endl;
                    flag=0;
                    break;
                }
            }
        }
        int tt=0;
        for(int i=1;i<=N;i++){
            if(flag)
            for(int j=1+i;j<=N;j++){
                if(!f(num[i],num[j]))
                    tt=1;
                if(tt==1&&(f(num[i],num[j])))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
