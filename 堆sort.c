#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 20
struct dui
{
    int num[MAXSIZE];
    int size;
};

int left (int);
int right(int);
void exchange(struct dui *,int,int);
void max_heap(struct dui *,int);
void build_dui(struct dui *);
void init_dui(struct dui *);

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2*i+1;
}
void exchange (struct dui *p,int i,int j)
{
    int q;
    q=p->num[i];
    p->num[i]=p->num[j];
    p->num[j]=q;
}
void max_heap(struct dui *p,int i)
{
    int largest=i;
    int l=left(i);
    int r=right(i);
    if(l<p->size&&p->num[l]>p->num[i]){
        largest=l;
        
    }
    if(r<p->size&&p->num[r]>p->num[largest]){
        largest=r;
       
    }
    if(largest!=i){
       	exchange(p,largest,i);    	
        max_heap(p,largest);
    }
}
void build_dui (struct dui *p)
{
    int len=p->size,i;
    for(i=len;i>=2;i--){
        exchange(p,i,1);
        p->size--;
        max_heap(p,1);
    }
}
void init_dui (struct dui *p)
{
	int i;
	for (i=p->size/2;i>=1;i--){
		max_heap(p,i);
	}
}
int main ()
{
	int i;
	struct dui a;
	a.size =10;
	for (i=1;i<=10;i++){
		a.num[i]=20-i;
	}
	init_dui(&a);
	build_dui (&a);
	for (i=1;i<=10;i++)
		printf (" %d ",a.num[i]);
	return 0;
}
