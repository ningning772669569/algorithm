#include "iostream"
#include "algorithm"
#include "bits/stdc++.h"
using namespace std;
struct node{
    int get, num, k;
};
int N;
int K;
int sum[10009];
int bnum[10009];
int sub[10009];
bool cmp(const node &p,const node &q)
{
    if(p.get!=q.get)
        return p.get>q.get;
    if(p.num!=q.num)
        return p.num>q.num;
    return p.k<q.k;
}
int main ()
{
    cin >>N;
    memset(sum,0,sizeof(sum));
    memset(bnum,0,sizeof(bnum));
    memset(sub,0,sizeof(sub));

    for(int pnum=1;pnum<=N;pnum++){
        cin >>K;
        int psum=0;
        for(int i=1;i<=K;i++){
            int k,num;
            cin>>k>>num;
            sum[k]+=num;
            bnum[k]++;
            psum+=num;
        }
        sub[pnum]=psum;
    }
    vector<node> re;
    for(int i=1;i<=N;i++){
        int tep=sum[i]-sub[i];
        re.push_back((node){tep,bnum[i],i});
    }
    sort(re.begin(),re.end(),cmp);
    for(int i=0;i<re.size();i++){
        double tep=1.0*re[i].get/100;
        cout<<re[i].k<<" ";
        printf("%.2lf",tep);
        if(i<re.size()-1)
            cout<<endl;
    }
    return 0;
}
