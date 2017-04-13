#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn=10009;
vector<int> g[maxn];
int vis[maxn];
int dfs(int u,int col)
{
    //cout<<u<<"   "<<col<<endl;
    vis[u]=col;
    int re=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]!=-1){
            if(vis[v]==col){
                re=0;
                break;
            }
            continue;
        }
        re=re&&dfs(v,!col);
    }
    return re;
}
int main ()
{
    int T;
    int N,M;
    cin >>T;
    while(T--){
        cin >>N>>M;
        for(int i=0;i<=N;i++)
            g[i].clear();
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=M;i++){
            int l,r;
            cin >>l>>r;
            g[l].push_back(r);
            g[r].push_back(l);
        }
        int re=1;
        for(int i=1;i<=N;i++){
            if(vis[i]==-1)
                if(!dfs(i,0)){
                    re=0;
                    break;
                }

        }
        if(re)
            cout<<"Correct"<<endl;
        else
            cout<<"Wrong"<<endl;
    }
    return 0;
}
