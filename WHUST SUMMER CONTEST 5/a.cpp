#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
const int maxn=150;
int m,n;
struct node{
    int a,from,to;
};
vector<struct node> p[maxn];
int state;
struct Skill{
    int from;
    int to;
    int vis;
};
struct Skill skill[maxn];
//int m[maxn][maxn];
int check(int v,int u)
{
    memset(skill,0,sizeof(skill));
    state=0;
    for(vector<struct node>::size_type i=0;i<p[v].size();i++){
        int aa=p[v][i].a;
        int from=p[v][i].from;
        int to=p[v][i].to;
        if(skill[aa].vis==0){
            skill[aa].from=from;
            skill[aa].to=to;
            skill[aa].vis=1;
        }
        else{
            if(skill[aa].to<from){
                return -1;
            }
            else if(skill[aa].from>to){
                return -1;
            }
            else {
                skill[aa].from=max(from,skill[aa].from);
                skill[aa].to=min(skill[aa].to,to);
            }
        }
    }
    for(vector<struct node>::size_type i=0;i<p[u].size();i++){
        int aa=p[u][i].a;
        int from=p[u][i].from;
        int to=p[u][i].to;
        if(skill[aa].vis==0){
            continue;
        }
        else{
            if(skill[aa].from>to){
                if(state==0){
                    state=-1;
                }
                else if(state==1){
                    return -1;
                }
            }
            else if(skill[aa].to<from){
                if(state==0)    state=1;
                else if(state==-1)  return -1;
            }
            else{
                skill[aa].from=max(from,skill[aa].from);
                skill[aa].to=min(skill[aa].to,to);
            }
        }
    }
    return 1;
}
int main ()
{
    while(scanf("%d %d",&m,&n)==2){
        for(int i=0;i<maxn;i++){
            p[i].clear();
        }
        for(int i=1;i<=m;i++){
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                struct node tep;
                int a,b;
                char s[10];
                scanf("%d %s %d",&tep.a,&s,&b);
                if(s[0]=='<'){
                    tep.from=0;
                    tep.to=b;
                }
                else{
                    tep.from=b;
                    tep.to=100;
                }
                p[i].push_back(tep);
            }
        }
        int flag=1;
        for(int i=1;i<=m;i++){
            if(flag==0)
                break;
            for(int j=1;j<=m;j++){
                int re=check(i,j);
                if(re==-1){
                    flag=0;
                    break;
                }

            }
        }
        if(flag){

            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
