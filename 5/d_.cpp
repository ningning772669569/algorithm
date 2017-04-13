#include "cstring"
#include "cstdio"
#include "algorithm"
#include "iostream"
#include "queue"
#define maxn 500000
#define maxn_size 26
using namespace std;
char s[1000006];
char word[155][80];

struct ac_auto{

    int  ch[maxn][maxn_size];
    int f[maxn];
    int val[maxn];
    int last[maxn];
    int cnt[maxn];
    int tot;
    int idx(char c)
    {
        return c-'a';
    }
    void init()
    {
        tot=1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(cnt,0,sizeof(cnt));
    }
    void insert(char * s,int v)
    {
        int u=0;
        int n;
        n=strlen(s);
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[tot],0,sizeof(ch[tot]));
                val[tot]=0;
                ch[u][c]=tot++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }
    void output(int j)
    {
        if(j){
            cnt[val[j]]++;
            output(last[j]);
        }
    }
    void find(char * t)
    {

        int n=strlen (t);
        int j=0;
        for(int i=0;i<n;i++)
        {
            int c=idx(t[i]);
            while(j&&!ch[j][c]) j=f[j];
            j=ch[j][c];
            if(val[j]) output (j);
            else if(last[j])    output (last[j]);
        }

    }
    void get_fail()
    {
        queue<int>q;
        f[0]=0;
        for(int i=1;i<maxn;i++){
            int u=ch[0][i];
            if(u){
                f[u]=0;
                q.push(u);
                last[u]=0;
            }

        }
        while(!q.empty()){
            int r=q.front();
            q.pop();
            for(int c=0;c<maxn_size;c++){
                int u=ch[r][c];
                if(!u)continue;
                q.push(u);
                int v=f[r];
                while(v&&!ch[v][c]) v=f[v];
                f[u]=ch[v][c];
                last[u]=val[f[u]]? f[u] :last[f[u]];
            }
        }
    }
};
struct ac_auto ac;
int main ()
{

    int n;
    while(scanf("%d",&n)!=EOF&&n){
        ac.init();
        for(int i=1;i<=n;i++){
            cin >> word[i];
            ac.insert(word[i],i);
        }
        scanf("%s",s);
        ac.get_fail();
        ac.find(s);
        int Max=-1;
        for(int i=1;i<=n;i++){
            if(Max<ac.cnt[i])
                Max=ac.cnt[i];
        }
        printf("%d\n",Max);
        for(int i=1;i<=n;i++){
            if(ac.cnt[i]==Max)
                printf("%s\n",word[i]);
        }



    }
    return 0;
}
