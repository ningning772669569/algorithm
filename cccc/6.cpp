#include "iostream"
#include "algorithm"
#include "cstdio"
using namespace std;
int N;
int main()
{
    cin >>N;
    int num=0;
    for(int i=1;i<=N;i++){
        int tep;
        cin>>tep;
        if(tep%2)
            num++;
    }
    cout<<num<<" "<<N-num;
    return 0;
}
