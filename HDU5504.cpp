#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
typedef long long LL;
int N;
vector<LL> a,b,c;
LL re;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        a.clear();
        b.clear();
        c.clear();
        for(int i=1;i<=N;i++){
            LL tep;
            scanf("%I64d",&tep);
            if(tep>0)
                a.push_back(tep);
            else if(tep<0)
                b.push_back(tep);
            else
                c.push_back(tep);
        }
        sort(b.begin(),b.end());
        LL re;
        if(a.size()){
            re=1;
            for(int i=0;i<a.size();i++) re*=a[i];
            if(b.size() & 1)
                for(int i=0;i<b.size()-1;i++)
                    re*=b[i];
            else
                for(int i=0;i<b.size();i++)
                    re*=b[i];
        }
        else{
            if(b.size()>1){
                re=1;
                if(b.size() & 1)
                    for(int i=0;i<b.size()-1;i++)
                        re*=b[i];
                else
                    for(int i=0;i<b.size();i++)
                        re*=b[i];
            }
            else{
                if(c.size()>0)
                    re=0;
                else
                    re=b[0];
            }
        }
        printf("%I64d\n",re);
    }
    return 0;

}
