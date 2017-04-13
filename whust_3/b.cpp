#include "cstdio"
#include "iostream"
#include "cstring"
#include "stack"
#include "algorithm"
using namespace std;
typedef long long LL;
int num[2000002];
bool is[2000002];
struct node{
    LL sum;
    int pos;
    node(LL a,int b):sum(a),pos(b){}
};
int n;
stack<struct node> s;
int main()
{
    while(scanf("%d",&n)!=EOF&&n){

        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            num[i+n]=num[i];
            if(num[i]>0)
                is[i]=true;
            else
                is[i]=false;
        }
        LL sum=0;
        sum=sum+num[1];
        struct node tep(sum,1);
        s.push(tep);
        for(int i=2;i<=2*n;i++)
        {
            sum=sum+num[i];
            if(s.top().sum<=sum){
                tep.sum=sum;tep.pos=i;
                s.push(tep);
            }
            else{
                int poslast;
                while(!s.empty()&&s.top().sum>sum){
                    poslast=s.top().pos;
                    s.pop();
                }
                if(i-poslast<=n)
                memset(is+poslast,0,sizeof(bool)*(i-poslast));
                else{
                memset(is+i-n,0,sizeof(bool)*(2*n-i));
                }
            }
        }
        int re=0;
        for(int i=1;i<=n;i++){
            if(is[i])
                re++;
        }
        printf("%d\n",re);

    }
}
