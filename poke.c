#include "stdio.h"
#include "stdlib.h"
int poke[14];
int result;
void dfs(int j);
int main ()
{

    int T,i;
    int n;
    int j;
    char num,color;
    scanf("%d",&T);
    int store[T+1];
    for(i=1;i<=T;i++){
        result=0;
        for(j=1;j<=14;j++)
            poke[j]=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            getchar();
            scanf("%c%c",&num,&color);
            if(num<='9'&&num>='2')
                poke[num-'2'+2]++;
            else if(num=='A')
                poke[1]++;
            else if(num=='T')
                poke[10]++;
            else if(num=='J')
                poke[11]++;
            else if(num=='Q')
                poke[12]++;
            else if(num=='K')
                poke[13]++;
        }
        for(j=1;j<=13;j++){
            if(poke[j]){
                    poke[j]--;
                    dfs(j);
                    poke[j]++;
                }
        }

        for(j=1;j<=13;j++){
            if(poke[j]>=2)
                result=result*poke[j];
        }
         store[i]=result;
    }

    for(i=1;i<=T;i++){
        store[i]=store[i]%(2^64);
        printf("Case #%d: %d\n",i,store[i]);
    }
    return 0;

}
void dfs(int j)
{
    int i;
    int state=0;
    for(i=1;i<=13;i++){
        if(i!=j){
            if(poke[i]){
                state=1;
                poke[i]--;
                dfs(i);
                poke[i]++;
            }

        }
    }
    if(state==0&&poke[j]==0)
        result++;
}

