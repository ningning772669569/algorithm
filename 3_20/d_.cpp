#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
int n;
const int maxn=100009;
int num[maxn];
set<pii> s;
set<pii> ss;
vector<int> vec;
int main ()
{
    freopen("fragmentation.in","r",stdin);
    freopen("fragmentation.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        vec.push_back(num[i]);
    }
    sort(vec.begin(),vec.end());
    vector<int>::iterator tail=unique(vec.begin(),vec.end());
    for(vector<int>::iterator i=vec.begin();i!=tail-1;i++){
        s.insert(make_pair(*i,*(i+1)));
    }
    vector<int> re;;
    int pos=1;
    int lastpos;
    while(pos<=n){
        int start=pos;
        while(pos<=n){
            lastpos=pos;
            pos++;
            if(num[lastpos]==num[pos]){
                continue;
            }
            else{
                if(s.count(make_pair(num[lastpos],num[pos]))&& !ss.count(make_pair(num[lastpos],num[pos]))){
                    ss.insert(make_pair(num[lastpos],num[pos]));
                    continue;
                }
                else{
                    re.push_back(pos-start);
                    break;
                }
            }
        }
    }
    printf("%d\n",re.size());
    for(unsigned int i=0;i<re.size();i++)
    {
        printf("%d ",re[i]);
    }
    return 0;
}
