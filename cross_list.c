#include "stdio.h"
#include "stdlib.h"
#define NU 10
#define MU 10
typedef struct OLNode{
	int i,j;
	int elem;
	struct OLNode * right, *down;
}OLNode,* OLink;

typedef struct{
	int nu,mu,tu;
	OLink * rhead;
	OLink * chead;
}CrossList;

int CreatList (CrossList * p,int num[][NU])
{
	OLNode * q;
	int i,j;
	p=(CrossList *)malloc(sizeof(CrossList));
	if(!p)
		return -1;	//必须要堆指针是否分配到了空间进行检测
	p->nu=NU;
	p->mu=MU;
	p->tu=0;		//初始化非零元素的个数
	/*for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			p->tu++;
	*/
	p->rhead=(OLink *)malloc(MU*sizeof(OLink));
	if(!p->rhead)
		return -1;
	for(i=0;i<MU;i++)
		p->rhead[i]=NULL;
	p->chead=(OLink *)malloc(NU*sizeof(OLink));
	if(!p->chead)
		return -1;
	for(i=0;i<NU;i++){
		p->chead[i]=NULL;	//初始化十字链表的两个维度的指针数组
	}
	for(i=0;i<MU;i++){
		for(j=0;j<NU;j++){
			if(num[i][j]){
				p->tu++;
				OLNode * tep;
				tep=(OLNode *)malloc(sizeof(OLNode));
				tep->i=i;
				tep->j=j;
				tep->elem=num[i][j];
				tep->right=NULL;
				tep->down=NULL;
				if(p->rhead[i]==NULL||p->rhead[i]->j>j){
					tep->right=p->rhead[i];
					p->rhead[i]=tep;	
				}
				else {
					q=p->rhead[i];
					while(q->right&&(q->right->j)<j)
						q=q->right;
					tep->right=q->right;
					q->right=tep;
				}
				if(p->chead[j]==NULL||p->chead[j]->i>i){
					tep->down=p->chead[j];
					p->chead[j]=tep;
				}
				else{
					q=p->chead[j];
					while(q->down&&q->down->i<i)
						q=q->down;		
					tep->down=q->down;
					q->down=tep;			
				}
			}
		}
	}	
}
int main ()
{
	return 0;
}
