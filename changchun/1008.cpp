#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
const int maxn=1010;
struct node {
    int v;
    struct node * l,*r;
    node(int v):v(v),l(NULL),r(NULL){}
    node():v(0),l(NULL),r(NULL){}
};
int n,q;
int num[maxn];
int qu[maxn];
int trace[maxn];
char tran[]={' ','E','W'};
node * r;
void inser(int u,node ** root)
{
    //node * root=*rootroot;
    //cout<<"^^^^^^^^^^^^"<<endl;
    if(*root==NULL){
        *root=new node(u);
        return ;
    }
    //cout<<"^^^^^^^^^^^^"<<endl;
    node * p=*root;
    node * last;
    while(p){
           // cout<<"^^^^^^^^^^^^"<<endl;
        last=p;
        if(u< p->v)
            p=p->l;
        else if(u> p->v)
            p=p->r;

    }
   // cout<<"^^^^^^^^^^^^"<<endl;
    if(last->v >u)
        last->l=new node(u);
    else
        last->r=new node(u);
        //cout<<"^^^^^^^^^^^^"<<endl;
}
node * init(int n)
{
    node * root=NULL;
    for(int i=1;i<=n;i++){
        inser(num[i],&root);
    }
    return root;
}
void search(int u)
{
    memset(trace,-1,sizeof(trace));
    int pos=1;
    node * p=r;
    while(p){
        if(p->v > u){
            p=p->l;
            trace[pos++]=1;
        }
        else if(p->v < u){
            p=p->r;
            trace[pos++]=2;
        }
        else{
            break;
        }
    }

    for(int i=1;trace[i]!=-1;i++)
        printf("%c",tran[trace[i]]);
    printf("\n");
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
     //   cout<<"^^^^^^^^^^^^"<<endl;
        r=init(n);
        //cout<<"^^^^^^^^^^^^"<<endl;
        scanf("%d",&q);
       // cout<<"^^^^^^^^^^^^"<<endl;
        for(int i=1;i<=q;i++){
            scanf("%d",&qu[i]);
            search(qu[i]);
        }
        ;
    }
}
