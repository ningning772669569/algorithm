#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "queue"
#include "utility"
using namespace std;
typedef pair<int,int> pii;
const int maxn=100010;
const int MAXN=1000010;
int N;
int a[maxn];
int b[maxn];
int c[maxn];
int aa[maxn];
int num[MAXN];
vector<pii> p;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        p.clear();
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            aa[i]=a[i];
        }
        sort(aa+1,aa+1+N);
        int asize=unique(aa+1,aa+1+N)-aa;
        //cout<<asize<<endl;
        for(int i=1;i<=N;i++){
            int l=lower_bound(aa+1,aa+asize,b[i])-aa;
            int r=lower_bound(aa+1,aa+asize,c[i])-aa;
            if(l==asize)
            {
                p.push_back(make_pair(b[i],c[i]));
                continue;
            }
            if(r==1 && aa[r]>c[i]){
                p.push_back(make_pair(b[i],c[i]));
                continue;
            }
            if(r==asize)
                r--;
            while(r>0 && aa[r]>c[i])
                r--;
            if(r-l+1>1)
                continue;
            else{
                if(aa[r]!=a[i])
                    continue;
                else{
                    p.push_back(make_pair(b[i],c[i]));
                }
            }
        }
        memset(num,0,sizeof(num));
        for(int i=0;i<p.size();i++){
            pii tep=p[i];
            num[tep.first]++;
            num[tep.second+1]--;
        }
        //cout<<"   "<<p.size()<<endl;
        int sum=0;
        for(int i=1;i<MAXN-2;i++){
            ;
            num[i]=num[i]+num[i-1];
        }
        /*if(t==3){
            for(int i=1;i<=90;i++){
                cout<<i<<"  "<<num[i]<<endl;
            }

        }*/
        int pos=1;
        int re=0;
        while(pos<MAXN-5){

            if(num[pos]<=num[pos+1])
                pos++;
            else{
                re++;
                //cout<<pos<<endl;
                while(num[pos]>=num[pos+1])
                    pos++;
            }
        }
        //cout<<re<<endl;
        printf("Case #%d: %d\n",t,re+asize-1);

    }

}
