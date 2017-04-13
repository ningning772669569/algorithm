#include "stdio.h"
#include "string.h"
#define MAX 8
void bfs (int,int); 
int q [MAX*MAX];
int vis[8][8]; 
int fa[8][8];
int dis[8][8];
int map[8][8];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int m=8;
int n=8;
int main ()
{

}
void bfs(int x,int y)
{
	int front,rear,u,d;
	int nx,ny;
	front=0;
	rear=0;	
	u=x*m+y;
	q[rear]=u;
	rear++;
	vis[x][y]=1;
	fa[x][y]=u;
	dis[x][y]=0;
	while(front<rear){
		u=q[front];
		front++;
		x=u/m;
		y=u%y;
		for(d=0;d<4;d++){
			nx=x+dir[d][0];
			ny=y+dir[d][1];
			if(!vis[nx][ny]&&!map[nx][ny]&&nx>=0&&nx<n&&ny>=0&&ny<m){
				vis[nx][ny]=1;
				dis[nx][ny]=dis[x][y]+1;
				q[rear]=nx*m+ny;
				rear++;
				fa[nx][ny]=u;
			}
		}	
	}
}
