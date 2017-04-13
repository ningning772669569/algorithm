#include "algorithm"
#include "cstdio"
#include "iostream"
///字典数

using namespace std;

typedef struct Node {
    struct Node * next[2];
}Node;

int search (struct Node * root ,int num );
void insert (struct Node * root,int num);
struct Node * creat_new ();

int main ()
{
    int T;
    int n,m;
    cin >> T;

    for(int t=1;t<=T;t++){
        struct Node * root;
        int num,_max;
        cin >>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            insert(root,num);
        }
        printf("Case #%d:\n",t);
        for(int i=1;i<=m;i++){
            scanf("%d",&num);
            printf("%d\n",search(root,num));
        }


    }
    return 0;
}
void insert (struct Node * root,int num)
{
    int bit = 1<<31;
    struct Node * p;
    p=root;
    for(int i=31;i>=0;i++){
        if(num&bit==bit){
            if(p->next[1]==NULL){
                p->next[1]=creat_new();
            }
            p=p->next[1];
        }
        else{
            if(p->next[0]==NULL)
                p->next[0]=creat_new();
            p=p->next[0];
        }
        num<<1;
    }
}
struct Node * creat_new ()
{
    struct  Node * _new;
    _new=(struct Node *)malloc(sizeof(struct Node));
    _new->next[1]=NULL;
    _new->next[0]=NULL;
    return _new;
}
int search (struct Node * root ,int num )
{
    int bit=1<<31;
    int re=0;
    struct Node * p;
    p=root;
    for(int i=31;i>=0;i++){
        if(num&bit==bit){
            if(p->next[0]){
                p=p->next[0];
                re=re|1;
                re<<1;
            }
            else{
                p=p->next[1];
                re<<1;
            }
        }
        else{
            if(p->next[1]){
                p=p->next[1];
                re=re|1;
                re<<1;
            }
            else {
                p=p->next[0];
                re<<1;
            }
        }
        num<<1;
    }
    return re;
}
