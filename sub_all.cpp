#include "cstdio"
#include "cstring"
#include <vector>
#include "algorithm"
#include "iostream"
using namespace std;
int main ()
{
    int n;
    cin >>n;
    vector<int> num;
    int a;
    for (int i=1;i<=n;i++){
        cin >>a;
        num.push_back(a);
    }
    vector<int>::iterator iter_front =num.begin();
    vector<int>::iterator iter_end =num.end();
    sort(iter_front,iter_end);

}
void sub(vector<int> num,int n,int cur)
