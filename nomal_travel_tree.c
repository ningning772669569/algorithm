#include "stdio.h"
#include "stdlib.h"
#define MAX 100
typedef struct tree_node
{
	int elem;
	struct tree_node *lchild;
	struct tree_node *rchild;
	struct tree_node *parrent;
}

typedef struct stack
{
	int top;
	int elem[MAX];
}
int main ()
{

}

void travel(tree_node * t)
{
	int tep;
	stack s;
	init_stack(s);
	push(s,t);
	while(!stack_empty(s)){
		while(tep=gettop(s)&&tep){
			tep=tep->lchild;	
			push(tep);
		}
		pop(s);//除掉最后加入的
	if(!stack_empty(s)){
		tep=pop(s);
		printf("%d ",tep->elem);
		push(tep->right);
	}
	}	

}
