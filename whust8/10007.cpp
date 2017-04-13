#include "cstdio"
#include "set"
using namespace std;
set<int> s;
int main ()
{
    int n;
    scanf("%d",&n);
    s.clear();
    while(n--){
        int ch;
        scanf("%d",&ch);
        if(ch==1){
            int num;
            scanf("%d",&num);
            s.insert(num);
        }
        if(ch==2){

            if(!s.empty()){

                s.erase(s.begin());
            }

        }
        else{
            if(!s.empty()){
                set<int>::iterator iter=s.end();
                iter--;
                printf("%d\n",*iter);
            }
            else{
                printf("0\n");
            }
        }
    }

}
