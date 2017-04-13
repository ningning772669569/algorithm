#include "stdio.h"
#include "stdlib.h"
int main ()
{
    int T,i;
    scanf("%d",&T);
    int m;                  ///循环用变量
    int result[T+1];
    int A,B,N,M;
    int Pos_B_x[101];       ///记录基站的位置
    int Pos_B_y[101];
    int Pos_A_x[1001];
    int Pos_A_y[1001];      ///记录用户的位置
    for(i=1;i<=T;i++){      ///for循环中也可以定义变量 但是该变量只可以在循环中使用
        scanf("%d %d %d %d",N,M,A,B);
        int size=0;                                                 ///堆得大小
        long long *Distance=(long long*)malloc((N+1)*(M+1)*sizeof(long long));       ///申明了一个堆 用malloc防止爆栈
        char ** visited=(char **)malloc((N+1)*(M+1)*sizeof(char));
        for(m=1;m<=A;m++){
            scanf("%d %d",&Pos_A_x[m],&Pos_A_y[m]);
        }
        for(m=1;m<=B;m++){
            scanf("%d %d",&Pos_B_x[m],&Pos_B_y[m]);
        }
    }

}
