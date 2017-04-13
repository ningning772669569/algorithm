#include "stdio.h"
#include "stdlib.h"

#define MAX 10
typedef struct DEQ{
	int * base ;
	int front;
	int rear;
}deq;
void init_deq(deq *p)
{
	p->base=(int *)malloc(MAX*sizeof(int));
	p->front=p->rear=0;	
}
void endeq(deq *p,int e)
{
	if((p->rear+1)%MAX==p->front){
		printf("循环列表已满\n");
		return ;
	}
	p->base[p->rear]=e;
	p->rear=(p->rear+1)%MAX;
	
}
int deldeq (deq *p)
{
	int tep_store;
	if(p->front==p->rear){
		printf("循环列表已空\n");
		return ;
	}
	tep_store=p->base[p->front];
	p->front=(p->front+1)%MAX;
	return tep_store;	
}
int main()
{
	char * a="ssss";
	int i;
	deq * pri;
	init_deq(pri);
	for(i=1;i<=11;i++)
	{
		endeq(pri,i);
	}
	for(i=1;i<=13;i++)
		deldeq(pri);
	return 0;

}
