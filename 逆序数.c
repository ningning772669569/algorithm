#include "stdio.h"
#include "stdlib.h"
typedef struct TREE{
    int val;
    int left;
    int right;
}SEGTREE;
int sum;
int smallest;
SEGTREE * initial (int num[],int n);
void build (SEGTREE tree[],int i,int left,int right);
void update(SEGTREE * tree,int i,int left,int right);
void query (SEGTREE * tree ,int i,int left,int right);
void build (SEGTREE tree[],int i,int left,int right);
int main ()
{
    int n,i;
    SEGTREE * tree;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    tree=initial(num,n);
    sum=0;
    for(i=n-1;i>=0;i--){
        //printf("%d\n",i);
        update(tree,1,num[i],num[i]);
        if(num[i]>smallest)
            query(tree,1,smallest,num[i]-1);
        printf("%d\n",sum);
    }
    printf("%d\n",sum);
    return 0;
}
SEGTREE * initial (int num[],int n)
{
    SEGTREE * tree = (SEGTREE *)malloc (sizeof(SEGTREE)*(4*n+2));
    int min=num[0],max=-num[0];
    int i;
    for(i=0;i<n;i++){
        if(min>num[i])
            min=num[i];
        if(max<num[i])
            max=num[i];
    }
    smallest=min;
    build(tree,1,min,max);
    return tree;

}
void build (SEGTREE tree[],int i,int left,int right)
{
    int mid;
    tree[i].val=0;
    tree[i].left=left;
    tree[i].right=right;

    if(left==right){
        return ;
    }
    mid=(right-left)/2+left;
    build(tree,i*2,left,mid);
    build(tree,i*2+1,mid+1,right);
}
void update(SEGTREE * tree,int i,int left,int right)
{
    //printf("     %d    %d\n",tree[i].left,tree[i].right);
    if(tree[i].left==left&&tree[i].right==right){
        tree[i].val++;
        return ;
    }
    int mid;
    mid=tree[i].left+(tree[i].right-tree[i].left)/2;

    if(mid<left){

        update(tree,2*i+1,left,right);

        }
    else if(mid>=right){

        update(tree,2*i,left,right);

        }

    else{

        update(tree,2*i,left,mid);
        update(tree,2*i+1,mid+1,right);

    }

}
void query (SEGTREE * tree ,int i,int left,int right)
{
    int mid;
    if(tree[i].left==tree[i].right)
    {
        sum=sum+tree[i].val;
        return ;
    }
    mid=tree[i].left+(tree[i].right-tree[i].left)/2;
    sum=sum+tree[i].val;
    if(mid<left)
        query(tree,i*2+1,left,right);
    else if(mid>=right)
        query(tree,i*2,left,right);
    else {
        query(tree,2*i,left,mid);
        query(tree,2*i+1,mid+1,right);
    }
}
