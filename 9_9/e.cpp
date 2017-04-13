#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include "math.h"
using namespace std;
const int maxn=10010;
int pos1[maxn];
int pos2[maxn];
int pos3[maxn];
int zeropos;
int num1,num2,num3,num4;
double num[maxn];
int n;
struct Keep{
    double a;
    int pos;
};
int re[maxn];
struct Keep keep[maxn];
bool cmp(const struct Keep &p,const struct Keep & q)
{
    return p.a<q.a;
}
int renum;
int main ()
{
    while(scanf("%d",&n)!=EOF){
        memset(keep,0,sizeof(keep));
        memset(pos1,0,sizeof(pos1));
        memset(pos2,0,sizeof(pos2));
        num1=num2=num3=0;
        zeropos=0;
        double minn=-1.0*(1000000);
        int minnpos;
        double maxn=-9;
        int maxnpos;
        for(int i=1;i<=n;i++){
            scanf("%lf",&num[i]);
        }
        for(int i=1;i<=n;i++){
            if(num[i]>1.0){
                num1++;
                pos1[num1]=i;
            }
            else if(num[i]<-1.0){
                num2++;
                pos2[num2]=i;

                if(minn<num[i]){
                    minn=num[i];
                    minnpos=i;
                }
            }
            else if(num[i]<0&&num[i]>=(-1.0)){
                num3++;
                keep[num3].pos=i;
                keep[num3].a=num[i];
            }
            else if(num[i]<=1&&num[i]>0){
                num4++;
                if(num[i]>maxn){
                    maxn=num[i];
                    maxnpos=i;
                }
            }
            else if(num[i]==0){
                if(!zeropos)
                    zeropos=i;
            }

        }
        sort(keep+1,keep+1+num3,cmp);
        int repos=0;
        int flag=0;
        int teppos1=1,teppos2=1;
        if(num2%2==0){

            renum=num1+num2;
            while(teppos1<=num1||teppos2<=num2){
                if(teppos2>num2||(teppos1<=num1&&pos1[teppos1]<pos2[teppos2])){
                    repos++;
                    re[repos]=pos1[teppos1];
                    teppos1++;
                }
                else if(teppos1>num1||(teppos2<=num2&&pos2[teppos2]<pos1[teppos1])){
                    repos++;
                    re[repos]=pos2[teppos2];
                    teppos2++;
                }
            }
        }

        else{

            if(num3){
                if(minn*keep[1].a>1.0){
                    flag=1;
                }
            }
            if(flag){
                //printf("%d\n",num1+num2+1);
                renum=num1+num2+1;
                while(teppos1<=num1||teppos2<=num2){
                if((teppos1<=num1&&pos1[teppos1]<pos2[teppos2])||teppos2>num2){
                    repos++;
                    re[repos]=pos1[teppos1];
                    teppos1++;
                }
                else if((teppos2<=num2&&pos2[teppos2]<pos1[teppos1])||teppos1>num1){
                    repos++;
                    re[repos]=pos2[teppos2];
                    teppos2++;
                }
                }
            }
            else{
                //printf("%d\n",num1+num2-1);
                renum=num1+num2-1;
                while(teppos1<=num1||teppos2<=num2){
                if((teppos1<=num1&&pos1[teppos1]<pos2[teppos2])||teppos2>num2){
                    repos++;
                    re[repos]=pos1[teppos1];
                    teppos1++;
                }
                else if((teppos2<=num2&&pos2[teppos2]<pos1[teppos1])||teppos1>num1){
                    if(pos2[teppos2]==minnpos){
                        teppos2++;
                        continue;
                    }
                    repos++;
                    re[repos]=pos2[teppos2];
                    teppos2++;
                }
                }
            }
        }
        if(renum<=0){
            if(num4>0||num3>1){
                if(num3<2||maxn>(keep[1].a*keep[2].a)){
                printf("1\n");
                printf("%d\n",maxnpos);}
                else{
                    printf("2\n");
                    int aa=keep[1].pos,bb=keep[2].pos;
                    if(aa>bb)
                        swap(aa,bb);
                    printf("%d %d\n",aa,bb);
                }

            }
            else if(num3==1){
                if(!zeropos){
                printf("1\n");
                printf("%d\n",keep[num3].pos);
                }
                else{
                    printf("1\n");
                    printf("%d\n",zeropos);
                }
            }

            continue;
        }
        printf("%d\n",renum);
        if(!flag){
            for(int i=1;i<=repos;i++){
                printf("%d",re[i]);
                if(i<repos)
                    printf(" ");
            }
            printf("\n");
        }
        else{
            int i=1;
            while(re[i]<keep[1].pos&&i<=repos){
                printf("%d ",re[i]);
                i++;
            }
            printf("%d ",keep[1].pos);
            for(;i<=repos;i++){
                printf("%d",re[i]);
                if(i<repos)
                    printf(" ");

            }
            printf("\n");
        }
    }
}
