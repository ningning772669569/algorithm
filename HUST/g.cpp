#include "cstdio"
#include "algorithm"
#include "iostream"
using namespace std;
int num[1009];
int n;
int main ()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        if(next_permutation(num+1,num+1+n)){
            for(int i=1;i<=n;i++){
                cout<<num[i];
                cout<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"WTF!"<<endl;
        }
    }
    return 0;
}
