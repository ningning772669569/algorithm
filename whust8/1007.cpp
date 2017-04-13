#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
#include "set"
#include "queue"
using namespace std;
int N;
struct cmp1{

    bool operator ()(const int a,const int b){
        return a<b;
    }
};

priority_queue<int,vector<int>,cmp1> q;
int MAX;
int main ()
{
    while(scanf("%d",&N)!=EOF){
        int MAX=-1*(1e9);
        for(int i=1;i<=N;i++){
            int choice;
            scanf("%d",&choice);
            if(choice==1){
                int num;
                scanf("%d",&num);
                if(MAX<num)
                    MAX=num;
                q.push(num);
            }
            else if(choice ==2){
                if(!q.empty())
                    q.pop();
            }
            else{
                if(!q.empty())
                    printf("%d\n",MAX);
                else
                    printf("0\n");
            }
        }
    }
}
