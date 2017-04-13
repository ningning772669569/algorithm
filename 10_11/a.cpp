#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <iomanip>
#include <utility>
#include <bitset>
using namespace std;
bool mp[250][250];
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n){
        memset(mp, 0, sizeof(mp));
        while(n--){
            int t, x, y, nx, ny;
            cin>>t>>x>>y;
            if(x<0){
                nx=-x+109;
            }
            else{
                nx=x;
            }
            if(y<0){
                ny=-y+109;
            }
            else{
                ny=y;
            }
            if(t==-1){
                mp[nx][ny]=0;
            }
            else if(t==1){
                mp[nx][ny]=1;
            }
            else{
                int mx=-111111111;
                for(int i=0; i<=218; i++){
                    for(int j=0; j<=218; j++){
                        int ci=i, cj=j;
                        if(ci>109){
                            ci=109-ci;
                        }
                        if(cj>109){
                            cj=109-cj;
                        }
                        if(mp[i][j]){
                            mx=max(mx, x*ci+y*cj);
                        }
                    }
                }
                cout<<mx<<'\n';
            }
        }
    }
    return 0;
}
