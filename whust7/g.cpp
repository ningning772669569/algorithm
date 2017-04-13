#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "set"
using namespace std;
typedef long long LL;
int n;
LL num[6][201];
set<LL> s1;
set<LL> s2;
set<LL> s3;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        s1.clear();
        s2.clear();
        s3.clear();
        scanf("%d",&n);
        for(int i=1;i<=5;i++){
            for(int j=1;j<=n;j++){
                scanf("%I64d",&num[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                s1.insert(num[1][i]+num[2][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                s2.insert(num[4][i]+num[5][j]);
            }
        }
        for(set<LL>::iterator iter=s1.begin();iter!=s1.end();iter++){
            for(int j=1;j<=n;j++){
                s1.insert((*iter)+num[3][j]);
            }
        }
        for(int i=1;i<=n;i++){
            s3.insert(num[3][i]);
        }
        int flag=0;
        for(set<LL>::iterator iter1 =s2.begin();iter1!=s2.end();iter1++){
            for(set<LL>::iterator iter2=s1.begin();iter2!=s1.end();iter2++){
                LL num=0-(*iter1)-(*iter2);
                if(s3.count(num)){
                    flag=1;
                    break;
                }
            }
        }
        if(flag){
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}
