#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
int n;
const int maxn=100009;
int num[maxn];
int geshu[maxn];
set<pii> s;
set<pii> ss;
vector<int> vec;
int main ()
{
    //freopen("fragmentation.in","r",stdin);
    //freopen("fragmentation.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        geshu[num[i]]++;
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
    int flag=0;
    while(pos<=n){
        int start=pos;
        flag=0;
        while(pos<=n){
            lastpos=pos;
            pos++;
            if(num[lastpos]==num[pos]){
                continue;
            }
            else{
                if(s.count(make_pair(num[lastpos],num[pos]))&& !ss.count(make_pair(num[lastpos],num[pos]))){
                    if(!flag){
                        ss.insert(make_pair(num[lastpos],num[pos]));
                        flag=1;
                        continue;
                    }
                    else{
                        int tep=lastpos;
                        while(tep>=1 && num[tep]==num[lastpos])
                            tep--;
                            //cout<<"!!!"<<endl;
                        if(lastpos-tep+1 == geshu[num[lastpos]]){
                            ss.insert(make_pair(num[lastpos],num[pos]));
                            continue;
                        }
                        else{
                            re.push_back(pos-start);
                            break;
                        }
                    }
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
