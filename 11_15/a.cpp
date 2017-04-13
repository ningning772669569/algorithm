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
typedef long long LL;
typedef pair<int,int> pii;
vector<pii> q;
priority_queue<int> pq;
int N;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        q.clear();
        for(int i=0;i<N;i++){
            int val;
            scanf("%d",&val);
            q.push_back(make_pair(val,i));
        }
        sort(q.begin(),q.end());
        while(!pq.empty())
            pq.pop();
        int pos=q.size(); pos--;
        int MAX=0;
        while(pos>=0){
            int r=pos;
            int l=pos;
            while(l>=0 && q[l].first==q[r].first)
                l--;
            l++;
            for(int i=l;i<=r;i++){
                if(!pq.empty()){
                    int tepmax=pq.top();
                    MAX=max(tepmax-q[i].second,MAX);
                }
            }
            for(int i=l;i<=r;i++)
                pq.push(q[i].second);
            pos=l-1;
        }
        cout<<MAX<<endl;
    }

}
