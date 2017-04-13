#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"
#include "vector"
#include "stack"
using namespace std;
char in[10];
char out[10];
vector<string> mid;
stack<int>  b,a;
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF){
        scanf("%s",in);
        scanf("%s",out);
        while(!a.empty()){
            a.pop();
        }
        while(!b.empty())
            b.pop();
        for(int i=N-1;i>=0;i--)
            b.push(out[i]-'0');
        a.push(in[0]-'0');
        mid.push_back("in\n");
        int pos=1;
        while(pos<N){
            while(!a.empty()&&a.top()==b.top()){
                a.pop();b.pop();
                mid.push_back("out\n");
            }
            while((pos<N)&&((in[pos]-'0')!=b.top())){
                a.push(in[pos]-'0');
                mid.push_back("in\n");
                pos++;
            }

            a.push(in[pos]-'0');
            mid.push_back("in\n");
            pos++;

        }
        while(!a.empty()&&a.top()==b.top()){
                a.pop();b.pop();
                mid.push_back("out\n");
            }
        if(b.empty()){
            printf("Yes.\n");
            for(vector<string>::size_type j=0;j<mid.size();j++){
                printf("%s",mid[j].c_str());
            }

        }
        else
            printf("No.\n");
        printf("FINISH\n");
        mid.clear();
    }
    return 0;
}
