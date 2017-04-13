#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "math.h"
#define eps 1e-8
#define MAX 1003
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
using namespace std;
int up[MAX];
int down[MAX];
int num[MAX];
int posx[MAX];
int posy[MAX];
int times[MAX];

struct point{
    double x,y;

};
struct point points[5];
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int inside_convex_v2(point q,int n,point* p){
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[1]|s[2];
}
int main ()
{
    int n;

    int m,x1,y1,x2,y2;
    while(scanf("%d",&n)==1&&n){
        memset(times,0,sizeof(times));
        memset(num,0,sizeof(num));
        scanf("%d %d %d %d %d",&m,&x1,&y1,&x2,&y2);
        for(int i=0;i<n;i++){
            scanf("%d %d",&up[i],&down[i]);
        }
        sort(up,up+n);
        sort(down,down+n);
        for(int i=0;i<m;i++){
            scanf("%d %d",&posx[i],&posy[i]);
        }
        for(int i=0;i<m;i++){
            point a;
            a.x=posx[i];a.y=posy[i];
            for(int j=0;j<=n;j++){
                if(j==0){
                    points[0].x=x1;
                    points[0].y=y1;
                    points[1].x=x1;
                    points[1].y=y2;
                    points[2].x=down[j];
                    points[2].y=y2;
                    points[3].x=up[j];
                    points[3].y=y1;
                }
                else if(j==n)
                {
                    points[0].x=up[j-1];
                    points[0].y=y1;
                    points[1].x=down[j-1];
                    points[1].y=y2;
                    points[2].x=x2;
                    points[2].y=y2;
                    points[3].x=x2;
                    points[3].y=y1;
                }
                else{
                    points[0].x=up[j-1];
                    points[0].y=y1;
                    points[1].x=down[j-1];
                    points[1].y=y2;
                    points[2].x=down[j];
                    points[2].y=y2;
                    points[3].x=up[j];
                    points[3].y=y1;
                }
                if(inside_convex_v2(a,4,points)){num[j]++;break;}

            }
        }
        for(int i=0;i<=n;i++){
            if(num[i])
                times[num[i]]++;
        }
        printf("Box\n");
        for(int i=0;i<=m;i++){
            if(times[i])
                printf("%d: %d\n",i,times[i]);
        }
    }
    return 0;

}

