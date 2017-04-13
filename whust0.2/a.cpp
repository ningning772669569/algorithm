#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "map"
using namespace std;
int N,M;
struct car{
    int p,q,k;
    bool out;
};
map<string,struct car> m;
map<string,int> cost;
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        m.clear();
        cost.clear();
        scanf("%d  %d",&N,&M);
        for(int i=1;i<=N;i++){
            int p,q,k;
            string name;
            cin >> name >>p>>q>>k;
            struct car tep;
            tep.p=p;tep.q=q;tep.k=k;tep.out=false;
            m[name]=tep;
        }
        for(int i=1;i<=M;i++){
            int time;
            string spy;
            char c;
            cin >> time;
            cin >> spy;
            cin >> c;
            if(c=='p'){

            }
            else if(c=='r'){

            }
            else{

            }


        }
    }
}
