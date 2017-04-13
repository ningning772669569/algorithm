#include "algorithm"
#include "cstdio"
#include "iostream"
#include "cstring"
#define INF 999999999
using namespace std;
struct Seq{
    int l,r,num;
};
int num[200005];
struct Seq seq[800010];
int N,M;
void build(int l,int r,int i)
{
    if(l==r){
        seq[i].l=l;
        seq[i].r=r;
        seq[i].num=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*i);
    build(mid+1,r,2*i+1);
    seq[i].num=max(seq[2*i].num,seq[2*i+1].num);
    seq[i].l=l;
    seq[i].r=r;
}
int query(int l,int r,int i)
{
    if(seq[i].l==l&&seq[i].r==r){
        return seq[i].num;
    }
    int mid;
    mid=(seq[i].l+seq[i].r)>>1;
    if(r<=mid){
        return query(l,r,2*i);
    }
    else if(l>mid)
        return query(l,r,2*i+1);
    else {
        return max(query(l,mid,2*i),query(mid+1,r,2*i+1));
    }
}

void initial()
{

    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
    }
    build(1,N,1);
}
void push_up(int i)
{
    if(i){
        seq[i].num=max(seq[i*2].num,seq[i*2+1].num);
        push_up(i/2);
    }

}
void update (int l,int r ,int i,int num)
{
    if(seq[i].l==l&&seq[i].r==r){
        seq[i].num=num;
        push_up(i/2);
        return;
    }
    int mid=(seq[i].r+seq[i].l)>>1;
    if(r<=mid)
        update(l,r,2*i,num);
    else if(l>mid){
        update(l,r,2*i+1,num);
    }
    else{
        update(l,mid,2*i,num);
        update(mid+1,r,2*i+1,num);
    }
}
int main ()
{
    while(scanf("%d %d",&N,&M)!=EOF){
        initial();
        char choice;
        for(int i=1;i<=M;i++){
            getchar();
            scanf("%c",&choice);
            if(choice=='Q')
            {
                int a,b;
                scanf("%d %d",&a,&b);
                printf("%d\n",query(a,b,1));
            }
            else
            {
                int a,b;
                scanf("%d %d",&a,&b);
                update(a,a,1,b);
            }
        }
    }
    return 0;
}

