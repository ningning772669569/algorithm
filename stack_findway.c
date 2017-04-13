#include "stdio.h"
#include "stdlib.h"

#define SIZE 10
#define END_X 8
#define END_Y 8
#define START_X 1
#define START_Y 1

int in_limit(int,int);
void find_way(int,int);
int vis[10][10];
int map[10][10]={
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,1,1,1,0,0,0,0,1},
{1,0,0,0,1,0,0,0,0,1},
{1,0,1,0,0,0,1,0,0,1},
{1,0,1,1,1,0,1,1,0,1},
{1,1,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};
int dir_x[4]={1,0,-1,0};
int dir_y[4]={0,1,0,-1};
int find;

void find_way(int pos_x,int pos_y)
{
	int i,new_x,new_y;
	if(pos_x==END_X && pos_y==END_Y){
		find=1;
	}
	if(in_limit(pos_x,pos_y)&&!vis[pos_x][pos_y]&&!map[pos_x][pos_y]){
		vis[pos_x][pos_y]=1;
		for(i=0;i<4;i++){
			new_x=pos_x+dir_x[i];
			new_y=pos_y+dir_y[i];	
			find_way(new_x,new_y);
			vis[new_x][new_y]=0;
			if(find)
				return ;	
		}		
	}	
}

int in_limit(int pos_x,int pos_y)
{
	if(pos_x>=0&&pos_y>=0&&pos_x<SIZE&&pos_y<SIZE)
		return 1;
	return 0;	
}
int main ()
{
	find_way(START_X,START_Y);
	if(find)
		printf("has found!\n"); 
	else
		printf("no way!");
	return 0;
}
