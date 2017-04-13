#include "stdio.h"
#include "stdlib.h"
struct tree_node {
    int num;
    int color;
    struct tree_node * next;
};
struct result{
    int num;
    struct result * next;
};
int aaaa;
void insert (struct result * res,int i,int tep_result);
void get_num(struct tree_node * tree,int number);
int main ()
{
    int T,i;    ///用于整个程序的循环
    int n;    ///用于每一组数据的循环
    int j;
    int m,k;
    int q;      ///指令数目
    int choice;
    int tep_result;
    struct tree_node *p;
    struct result *pp;
    scanf("%d",&T);
    struct result res[T+1];
    for(i=1;i<=T;i++){
        res[i].next=NULL;
    }
    for(i=1;i<=T;i++){
            scanf("%d",&n);
        struct tree_node tree[n+1];   ///申明n个数的节点
        for(j=1;j<=n;j++){
            tree[j].color=0;
            tree[j].next=NULL;
            tree[j].num=0;          ///初始化///代表地下的字节点数量为0
        }
        for(j=1;j<=n-1;j++){
            scanf("%d %d",&m,&k);           ///读入边的信息 创建树
            p=(struct tree_node *)malloc(sizeof(struct tree_node));
            p->next=NULL;               ///必须初始化
            p->num=k;
            p->color=0;
            tree[m].num++;
            p->next=tree[m].next;
            tree[m].next=p;         ///插入边
        }
        scanf("%d",&q);
        for(j=1;j<=q;j++){
            scanf("%d",&choice);
            if(choice == 2){
                scanf("%d %d",&m,&k);
                tree[m].color=k;
            }
            else{
               aaaa=1;
               get_num(tree,1);
               tep_result=aaaa;
               insert(res,i,tep_result);
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("Case #%d:\n",i);
        pp=res[i].next;
        while (pp){
            printf("%d\n",pp->num);
            pp=pp->next;
        }
    }
    return 0;
}
void insert (struct result * res,int i,int tep_result)
{
    struct result * p,* a;
    p=&res[i];
    while(p->next){
        p=p->next;

    }
    a=(struct result*)malloc(sizeof(struct result));
    a->num=tep_result;
    a->next=NULL;
    p->next=a;
}
void get_num(struct tree_node * tree,int number)
{
    int color=tree[number].color;
    //int state=1;
    if(tree[number].num!=0){
        struct tree_node * p;
        p=tree[number].next;
        while (p){
            if(tree[p->num].color!=color)
            {
                aaaa++;


            }
            get_num(tree,p->num);
            p=p->next;
        }


    }

}
