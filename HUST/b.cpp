#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
int n,m;
int num[1009];
int c[1009];
bool cmp(const int &p,const int & q)
{
    return p>q;
}
int main ()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&c[i]);
        sort(num+1,num+1+n,cmp);
        sort(c+1,c+1+m,cmp);
        if(num[1]>m){
            cout<<"No"<<endl;
            continue;
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            int cur=num[i];
            for(int j=1;cur&&j<=m;j++){
                if(c[j]){
                    c[j]--;
                    cur--;
                }
            }
            if(cur!=0){
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
