#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn=100050;

const int MAXN = 100010;
//字符串长度<MAXN
int Ma[MAXN * 2];
int Mp[MAXN * 2];
int s[MAXN];
int n;
void Manacher(int s[]) {
    int l = 0, len = n;
    Ma[l++] = -1;
    Ma[l++] = 0;
    for (int i = 0; i<len; i++)  {
        Ma[l++] = s[i];
        Ma[l++] = 0;
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for (int i = 0; i<l; i++)  {
        Mp[i] = mx>i ? min(Mp[2 * id - i], mx - i) : 1;
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]])Mp[i]++;
        if (i + Mp[i]>mx)   {
            mx = i + Mp[i];    id = i;
        }
    }
    //int ans = 0;
    //for (int i = 0; i<2 * len + 2; i++)
        //ans = max(ans, Mp[i] - 1);
    //return ans;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        memset(Mp,0,sizeof(Mp));
        for(int i=0;i<=n;i++){
            scanf("%d",s[i]);
        }
        Manacher(s);
        int MAX=0;
        for(int i=2;i<MAXN;i+=2){
            int teplen=Mp[i]-1;
            teplen=teplen/2;
            if(Mp[i+teplen]==teplen){
                MAX=max(MAX,3*teplen);
            }
        }
        printf("Case #%d: %d\n",t,MAX);
    }
}
