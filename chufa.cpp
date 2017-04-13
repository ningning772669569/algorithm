#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
int vis[10];
int N;
int check(int);
int main ()
{
	int num1,num2,num3,num4,num5;
	int n;

	scanf("%d",&n);
	N=n;
	memset(vis,0,sizeof(vis));
	for(int i1=0; i1<10;i1++){
		num1=i1;
		//memset(vis,0,sizeof(vis));
		vis[i1]=1;
		for(int i2=0;i2<10;i2++){
			if(!vis[i2]){
				vis[i2]=1;
				num2=num1*10+i2;
				for(int i3=0;i3<10;i3++){
					if(!vis[i3]){
						vis[i3]=1;
						num3=num2*10+i3;
						for(int i4=0;i4<10;i4++){
							if(!vis[i4]){
								vis[i4]=1;
								num4=num3*10+i4;
								for(int i5=0;i5<10;i5++){
									if(!vis[i5]){
										vis[i5]=1;
										num5=num4*10+i5;
										if(check(num5))
											printf("%d\n",num5);
										vis[i5]=0;
									}
								}
								vis[i4]=0;	
							}
						}
						vis[i3]=0;
					}
					
				}
				vis[i2]=0;
			}
		}
		vis[i1]=0;
	}
	return 0;
}
int check(int num)
{
	int vis2[10];
	int i;
	memset(vis2,0,sizeof(vis2));
	num=num*N;
	while(num){
		i=num%10;
		if(vis[i]||vis2[i])
			return 0;
		num=num/10;
		vis2[i]=1;
	}
	return 1;
}
