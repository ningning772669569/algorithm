#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "queue"
#include "utility"
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int N;
char m[15][15];
vector<pii> p1;
vector<pii> p2;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        p1.clear();
        p2.clear();
        scanf("%d",&N);
        vector<char> num;
        for(int i=1;i<=N;i++){
            getchar();
            for(int j=1;j<=N;j++){
                scanf("%c",&m[i][j]);
                if(m[i][j]=='1')
                    p1.push_back(make_pair(i,j));
                if(m[i][j]=='2')
                    p2.push_back(make_pair(i,j));
            }

        }
        for(int i=1;i<=N;i++){
            if(m[1][i]!='.')
                num.push_back(m[1][i]);
        }
        for(int i=2;i<=N;i++){
            if(m[i][N]!='.')
                num.push_back(m[i][N]);
        }
        for(int i=N-1;i>=1;i--){
            if(m[N][i]!='.')
                num.push_back(m[N][i]);
        }
        for(int i=N-1;i>=2;i--){
            if(m[i][1]!='.')
                num.push_back(m[i][1]);
        }
        if(!(num.size()==4 && p1.size()==2 &&p2.size()==2)){
            cout<<"-1"<<endl;
            continue;
        }
        if(N<2){
            cout<<"-1"<<endl;
            continue;
        }
        int okflag=0;
    /*
        for(int i=0;i<4;i++){
            cout<<"#"<<num[i]<<" ";
        }
        cout<<endl;
    */  for(int i=0;i<=3;i++){
            int npos=(i+1)%4;
            if(num[npos]==num[i]){
                okflag=1;
            }
        }
        if(!okflag){
            cout<<"-1"<<endl;
            continue;
        }
        //cout<<"!!!!!!"<<endl;
        int re=0;
        re+=abs(p1[1].first-p1[0].first);
        re+=abs(p1[1].second-p1[0].second);
        re+=abs(p2[1].first-p2[0].first);
        re+=abs(p2[1].second-p2[0].second);
        //cout<<"!!!!!!"<<endl;
        if(p1[1].first==p1[0].first &&p2[1].first==p2[0].first && p1[1].first==p2[0].first){
            int mi1,mi2,ma1,ma2;
            mi1=min(p1[1].first,p1[0].first);
            ma1=max(p1[1].first,p1[0].first);
            mi2=min(p2[1].first,p2[0].first);
            ma2=max(p2[1].first,p2[0].first);
            if(ma2>ma1){
                    if(mi2<mi1)
                        re+=2;
            }
            if(ma1>ma2){
                if(mi1<mi2)
                    re+=2;
            }
        }
        if(p1[1].second==p1[0].second &&p2[1].second==p2[0].second && p1[1].second==p2[0].second)
        {
            int mi1,mi2,ma1,ma2;
            mi1=min(p1[1].second,p1[0].second);
            ma1=max(p1[1].second,p1[0].second);
            mi2=min(p2[1].second,p2[0].second);
            ma2=max(p2[1].second,p2[0].second);
            if(ma2>ma1){
                    if(mi2<mi1)
                        re+=2;
            }
            if(ma1>ma2){
                if(mi1<mi2)
                    re+=2;
            }
        }
        re+=2;
        cout<<re<<endl;
    }

}
