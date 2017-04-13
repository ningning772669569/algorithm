#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "set"
#define MAX 75
using namespace std;

typedef long long LL;
int  n, p;
set <LL> s, dabiao[MAX+1];
void initial(){

    for(int i = 0; i <= MAX; i++) dabiao[i].clear();

    for(int i = 1; i <= 70; i ++){
        dabiao[i].insert(i);
        for(int j = 1; j < i; j ++){
            for(set <LL> :: iterator it = dabiao[j].begin(); it != dabiao[j].end(); it ++){
                dabiao[i].insert((i - j) * (LL) (* it));
            }
        }
    }
}
int main(){
    initial();
    int T;
    scanf("%d",&T);
    while( T --){
        scanf("%d%d",&n, &p);
        s.clear();
        for(set <LL> :: iterator  it = dabiao[n].begin(); it != dabiao[n].end(); it ++){
            s.insert((*it) % p);
        }
        printf("%d\n", s.size());
    }
    return 0;
}
