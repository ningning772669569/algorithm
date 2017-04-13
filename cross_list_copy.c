#include "stdio.h"
#include "stdlib.h"
#define NU 10
#define MU 10
typedef struct OLNode{
	int i,j;
	int elem;
	struct OLNode * right, *down;
}OLNode;
typedef struct OLNode * OLink;

typedef struct{
	int nu,mu,tu;
	OLink * rhead;
	OLink * chead;
}CrossList;

int A[10][10]={
{0,0,0,0,0,0,1,0,0,0},
{1,2,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,2,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,0,0}
};

int B[10][10]={
{0,0,0,0,0,0,1,0,0,0},
{1,2,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,2,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,0,0}
};

int CreatList (CrossList * p,int num[][NU])
{
	OLNode * q;
	int i,j;
	OLNode *tep;
	//p=(CrossList *)malloc(sizeof(CrossList));  这里不能对传过来的指针进行malloc划分空间
	//if(!p)
		//return -1;	//必须要堆指针是否分配到了空间进行检测
	p->nu=NU;
	p->mu=MU;
	p->tu=0;		//初始化非零元素的个数
	/*for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			tep->tu++;
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
				//OLNode * tep;
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
	return 1;
}

int sub_cross_list(CrossList *p,CrossList *q)
{
	int i;
	if(p->nu!=q->nu||p->mu!=q->mu){
		return -1;	//不满足矩阵相加的条件
	}
	OLink hl[NU];	
	OLNode * pa,*pb,*pre;
	OLink tep;
	pa=p->rhead[0];
	pb=q->rhead[0];
	for(i=0;i<NU;i++){
		hl[i]=p->chead[i];
	}
	for(i=0;i<MU;i++){
		pa=p->rhead[i];
		pb=q->rhead[i];
		pre=NULL;
		while(pb!=NULL){
			//OLink  p;
			if(!(tep=(OLNode *)malloc(sizeof(OLNode)))){
				return -1;
			}
			tep->elem=pb->elem;
			tep->i=pb->i;
			tep->j=pb->j;
			tep->right=NULL;
			tep->down=NULL;
			if(pa==NULL||pa->j>pb->j){
				if(pre==NULL){
					p->rhead[tep->i]=tep;
				}
				else{
					pre->right=tep;
				}
				tep->right=pa;
				pre=tep;

			//将p的列指针串起来
				if(!p->chead[tep->j]||p->chead[tep->j]->i>tep->i){
					tep->down=p->chead[tep->j];
					p->chead[tep->j]=tep;
				}
				else{
					tep->down=hl[tep->j]->down;
					hl[tep->j]->down=tep;
				}
				hl[tep->j]=tep; //更新纵方向上的上一级指针数组，注意不能放到大括号里面
				pb=pb->right;
			}
			else if(pa!=NULL&&pa->i<pb->j){
				pre=pa;
				pa=pa->right;
			}
			else if(pa->j==pb->j){
				pa->elem=pa->elem+pb->elem;
				if(pa->elem==0){
					if(pre==NULL){
						p->rhead[pa->i]=pa->right;
					}
					else{
						pre->right=pa->right;
					}	
					tep=pa;
					pa=pa->right;//如果不把这一句加上在后来释放以后pa这个指针就失效了，也就没办法后面通过pa找到插入							    //位置
					if(p->chead[tep->j]==tep){
						p->chead[tep->j]=tep->down;
						hl[tep->j]=tep->down;
					}
					else{
						hl[tep->j]->down=tep->down;
						
					}
					free(tep);
				
				//printf("0");	
				}
				else{
					hl[pa->j]=pa;
				}
				//hl[pa->j]=pa;
				pb=pb->right;
			}
			
		}
	}
}
void show (CrossList * p)
{
	int i,j;
	OLink tep;
	for(i=0;i<MU;i++){
		tep=p->rhead[i];
		if(tep){
			while(tep->right){
				printf("%2d",tep->elem);
				for(j=tep->j;j<tep->right->j-1;j++)
					printf("  ");
				tep=tep->right;
			}
			printf("%2d",tep->elem);
		}
		printf("\n");
	}
}

int main ()
{
	CrossList p,q;
	CreatList(&p,A);
	CreatList(&q,B);
	sub_cross_list(&p,&q);
	//show(&p);
	//printf("%d",p.rhead[1]->elem);
	return 0;
}
