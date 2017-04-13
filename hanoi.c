#include "stdio.h"
#include "stdlib.h"
void hanoi (int,char,char,char);
void move(char,int,char);
int count;

int main ()
{
	char x='a';
	char y='b';
	char z='z';
	int n;
	scanf("%d",&n);
	hanoi(n,x,y,z);
	printf("%d\n",count);
	return 0;
}
void move (char x,int n,char z)
{
	++count;
}


void hanoi (int n,char x,char y,char z)
//将塔座x上的n个圆盘搬到z上面
//move是搬动操作
{
	if(n==1)
		move(x,1,z);
	else{
		hanoi(n-1,x,z,y);
		move(x,n,z);
		hanoi(n-1,y,x,z);
	}
}
