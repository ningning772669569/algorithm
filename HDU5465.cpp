#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=505;
const int size=maxn*2;
int num[maxn][maxn];
int tree[size+1][size+1];
int N,M,Q;
int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y,int delta)
{
    int i,j;
    for(i=x;i<=N*2;i+=lowbit(i))
    {
        for(int j=y;j<=N*2;j+=lowbit(j))
            {tree[i][j]=tree[i][j]^delta;
                //cout<<tree[i][j]<<endl;
            }
    }
}

int sum(int x,int y)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            res=res^tree[i][j];
        }
    }
    return res;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(num,0,sizeof(num));
        memset(tree,0,sizeof(tree));
        scanf("%d%d%d",&N,&M,&Q);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                scanf("%d",&num[i][j]);
                update(i,j,num[i][j]);
            }
        }
        for(int i=1;i<=Q;i++){
            int choice;
            scanf("%d",&choice);
            if(choice==1){
                int x1,x2,y1,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                int re=0;
                re=re^sum(x1-1,y1-1);
                //cout<<re<<endl;
                re=re^sum(x2,y2);
                //cout<<re<<endl;
                re=re^sum(x1-1,y2);
               //cout<<re<<endl;
                re=re^sum(x2,y1-1);
                //cout<<re<<endl;
                if(re==0)
                    printf("No\n");
                else
                    printf("Yes\n");
            }
            else{
                int x,y,d;
                scanf("%d%d%d",&x,&y,&d);
                update(x,y,d^num[x][y]);
                num[x][y]=d;
            }
        }
    }
}
