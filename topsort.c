#include "stdio.h"
#include "stdli,b"
int visit[1000];
int G[1000][1000];
int num[1000];
int n=8;
int t=n;

bool topsort(int i);

int main ()
{
	int i;
	for(i=1;i<=8;i++){
		visit[i]=0;
	}
}
bool topsort(int i)
{

	int j;
	visit[n]=-1;
	for(j=1;j<=n;j++){
		if(G[i][j]){
			if(visit[j]<0)
				return false;
			else if(!visit[j]&&topsort(j))
				return false;
		}	
	}
	visit[i]=1;
	num[t--]=i;
	return true;
}
