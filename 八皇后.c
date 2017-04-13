#include "stdio.h"
/**如果在回溯中运用了辅助的全局变量一定要在回溯之前将他们的改变复原，不然会导致无法求解问题**/
void search (int );
int total=0;
int pos[8];
int main()
{
    search(0);
    printf("%d",total);
    return 0;
}
void search (int n)
{
    int i,j;
    int ok;
    if(n==8){
        total++;
        return;
    }
    for(i=0;i<8;i++){
        ok=1;
        for(j=0;j<n;j++){
            if(i==pos[j]||(n-j)==(i-pos[j])||(n-j)==pos[j]-i){
                ok=0;
                break;
            }
        }
        if(ok==1){
            pos[n]=i;
            search(n+1);
        }
    }
}
