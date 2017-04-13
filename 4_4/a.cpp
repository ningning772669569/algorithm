#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "math.h"
using namespace std;
typedef long long LL;
struct point{double x,y;};
struct point area[50002];
double sum[50002];
double xmult(struct point p1,struct point p2,struct point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double area2(struct point p1,struct point p2,struct point p3){
	return fabs(xmult(p1,p2,p3))/2;
}
int n,q;
int main()
{
    while(scanf("%d %d",&n,&q)==2){
        double x,y;
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            area[i].x=x;area[i].y=y;
        }
        sum[0]=0;
        double all=0;
        for(int i=1;i<n-1;i++){
            sum[i]=sum[i-1]+area2(area[0],area[i],area[i+1]);

        }
        all=sum[n-2];


        for(int i=1;i<=q;i++){
            double tmp_area;
            int a,b;
            scanf("%d %d",&a,&b);
            if(a>b)
                swap(a,b);
           if(a == 0)
                tmp_area = fabs(sum[b-1]);
            else if(b == n-1)
                tmp_area = all - fabs(sum[a-1] + area2(area[0], area[a], area[b]));
            else
                tmp_area = fabs(sum[b-1] - sum[a-1] - area2(area[0], area[a], area[b]));
            printf("%.1lf\n", min(tmp_area, all - tmp_area));
        }
    }
}
