#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
vector<int> blo[30];
int pos[30];
int n;
int get(char s1[],char s2[])
{
    if(s1[0]=='m'){
        if(s2[1]=='n')
            return 1;
        else
            return 2;
    }
    else{
        if(s2[1]=='n'){
            return 3;
        }
        else
            return 4;
    }

}
void exe(int mode,int from,int to)
{
    int a,b;
    if(from==to||pos[from]==pos[to])
        return ;
    a=pos[from];
    b=pos[to];
    if(mode ==1 ){
        int start;
        for(int i=0;i<blo[a].size();i++){
            if(blo[a][i]==from){
                start=i;
                break;
            }
        }
        for(int i=start+1;i<blo[a].size();i++){
            int t=blo[a][i];
            blo[t].push_back(t);
            pos[t]=t;
        }
        int tep=blo[a].size();
        for(int tt=1;tt<=tep-start;tt++)
            blo[a].pop_back();

        for(int i=0;i<blo[b].size();i++){
            if(blo[b][i]==to){
                start=i;break;
            }
        }
        for(int i=start+1;i<blo[b].size();i++){
            int t=blo[b][i];
            blo[t].push_back(t);
            pos[t]=t;
        }
        tep=blo[b].size();
        for(int i=1;i<tep-start;i++){
            blo[b].pop_back();
        }
        blo[b].push_back(from);
        pos[from]=b;
    }
    else if(mode == 2)
    {
        int start;
        for(int i=0;i<blo[a].size();i++){
            if(blo[a][i]==from){
                start=i;
                break;
            }
        }
        for(int i=start+1;i<blo[a].size();i++){
            int t=blo[a][i];
            blo[t].push_back(t);
            pos[t]=t;
        }
        int tep=blo[a].size();
        for(int i=1;i<=tep-start;i++)
            blo[a].pop_back();
        blo[b].push_back(from);
        pos[from]=b;
    }
    else if(mode == 3){
        int start;
        for(int i=0;i<blo[b].size();i++){
            if(blo[b][i]==to){
                start=i;
                break;
            }
        }
        for(int i=start+1;i<blo[b].size();i++){
            int t=blo[b][i];
            blo[t].push_back(t);
            pos[t]=t;
        }
        int tep=blo[b].size();
        for(int i=1;i<tep-start;i++)
            blo[b].pop_back();

        for(int i=0;i<blo[a].size();i++){
            if(blo[a][i]==from){
                start=i;
                break;
            }
        }
        for(int i=start;i<blo[a].size();i++){
            int t=blo[a][i];
            pos[t]=b;
            blo[b].push_back(t);
        }
        tep=blo[a].size();
        for(int i=1;i<=tep-start;i++)
            blo[a].pop_back();


    }
    else{
        int start;
        for(int i=0;i<blo[a].size();i++){
            if(blo[a][i]==from){
                start=i;
                break;
            }
        }
        for(int i=start;i<blo[a].size();i++){
            int t=blo[a][i];
            blo[b].push_back(t);
            pos[t]=b;
        }
        int tep=blo[a].size();
        for(int i=1;i<=tep-start;i++){
            blo[a].pop_back();
        }
    }
}
void show()
{
    for(int i=0;i<n;i++){
        printf("%d:",i);
        if(!blo[i].empty())
        for(int j=0;j<blo[i].size();j++){
            printf(" %d",blo[i][j]);
        }
        printf("\n");
    }
}
int main ()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++){
            blo[i].clear();
            blo[i].push_back(i);
            pos[i]=i;
        }
        int a,b;
        char s1[20],s2[20];
        while(1){
            scanf("%s",s1);
            if(s1[0]=='q')
                break;
            scanf("%d %s %d",&a,s2,&b);
            int mode=get(s1,s2);
            exe(mode,a,b);
        }
        show();

    }
}
