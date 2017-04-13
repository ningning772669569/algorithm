#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
int n;
LL num[maxn];
vector<LL> m;

int main ()
{
    while(scanf("%d",&n)!=EOF){
        memset(num,0,sizeof(num));
        LL maxnum=0;
        m.clear();
        LL geshu=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&num[i]);
            if(num[i]>maxnum)
                maxnum=num[i];

        }
        for(int i=1;i<=n;i++){
            if(num[i]==maxnum){
                m.push_back(i);
            }
            if(num[i]==maxnum-1){
                geshu++;
            }
        }
        LL ans=maxnum*m.size();
        LL sum=maxnum*m.size();
        vector<int>::size_type p;
        for(p=0;p<m.size();p++){

            if(m[p]>1){
                int l=m[p]-1;
                if(num[l]<num[m[p]]-2){
                    if(m.size()==1)
                        ans=min(ans,maxnum-1+geshu*(maxnum-1));
                    else{
                        ans=min(ans,sum-maxnum);
                    }
                }
                if(num[l]==num[m[p]]-2){
                    if(m.size()==1){
                        ans=min(ans,(maxnum-1)*(geshu+2));
                    }
                    else{
                        ans=min(ans,sum-maxnum);
                    }
                }
                if(num[l]){
                    ans=min(ans,maxnum+1);
                }
            }
            if(m[p]<n){
                int r=m[p]+1;
                if(num[r]<num[m[p]]-2){
                    if(m.size()==1)
                        ans=min(ans,geshu*(maxnum-1)+maxnum-1);
                    else{
                        ans=min(ans,sum-maxnum);
                    }
                }
                if(num[r]==num[m[p]]-2){
                    if(m.size()==1){
                        ans=min(ans,(maxnum-1)*(geshu+2));
                    }
                    else{
                        ans=min(ans,sum-maxnum);
                    }
                }
                if(num[r]){
                    ans=min(ans,maxnum+1);
                }
            }
        }

        printf("%I64d\n",ans);
    }
}
