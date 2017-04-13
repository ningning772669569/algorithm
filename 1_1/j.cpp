#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
int N;
struct tree{
    int pos;
    int num;
};
struct tree ltree[101];
struct tree rtree[101];
int rnum;
int lnum;
int cmpr(const struct tree &p,const struct tree &q)
{
    return p.pos<q.pos;
}
int cmpl(const struct tree&p,const struct tree &q)
{
    return p.pos>q.pos;
}
int main ()
{
    while (scanf("%d",&N)!=EOF){
        rnum=0;lnum=0;
        for(int i=1;i<=N;i++){
            int pos,num;
            scanf("%d %d",&pos,&num);
            if(pos<0){

                ltree[lnum].pos=pos;
                ltree[lnum].num=num;
                lnum++;
            }
            else{

                rtree[rnum].pos=pos;
                rtree[rnum].num=num;
                rnum++;
            }

        }
        sort(rtree,rtree+rnum,cmpr);
        sort(ltree,ltree+lnum,cmpl);
        long long re=0;
        if(lnum>rnum){
            for(int i=0;i<rnum;i++)
                re=re+rtree[i].num;
            for(int i=0;i<=rnum;i++){
                re=re+ltree[i].num;
            }
        }
        else if(rnum>lnum){
            for(int i=0;i<lnum;i++){
                re=re+rtree[i].num;
                re=re+ltree[i].num;

            }
            re=re+rtree[lnum].num;
        }
        else{
            for(int i=0;i<rnum;i++){
                re=re+rtree[i].num;
                re=re+ltree[i].num;
            }
            re=re+max(ltree[lnum].num,rtree[rnum].num);
        }
        printf("%I64d\n",re);
    }
    return 0;
}
