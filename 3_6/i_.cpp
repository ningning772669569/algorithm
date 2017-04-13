#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef  unsigned long long ll;
typedef long long LL;
typedef pair<long long,long long> pll;
ll cm[100][100];
ll mk[100], mk_2[100];
LL l,r,x;
LL step[70];
LL Re;
LL c[70][70];
void msk() {
    mk[1] = 1;
    for (int i = 2; i <= 60; i++) {
        mk[i] = mk[i - 1] * 2 + 1;
    }
    mk_2[1] = 1;
    for (int i = 2; i <= 60; i++) {
        mk_2[i] = mk_2[i - 1] * 2;
    }
}

void comb() {
    for (int i = 1; i <= 64; i++) {
        cm[i][0] = 1;
        cm[i][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 1; j < i; j++) {
            cm[i][j] = cm[i - 1][j] + cm[i - 1][j - 1];
        }
    }
}

ll cal(ll m, ll x) {
    if (m < x) {
        return 0;
    }
    else if (m == x) {
        return 1;
    }
    else {
        return cm[m][x];
    }
}

ll cnt(ll m, ll q) {
    ll xc{m}, ans{0};
    int i;
    for (i = 60; i >= 2; i--) {
        if ((xc & mk[i]) >= mk_2[i]) {
            break;
        }
    }
    for (; i >= 2; i--) {
            if(q==0){
                break;
            }
        if ((xc & mk[i]) >= mk_2[i]) {
            ans += cal(i - 1, q--);
        }
    }
    return ans;
}
LL ones(LL n)
{
    LL re=0;
    while(n){
        if(n & 1)
            re++;
        n/=2;
    }
    return re;
}
void init()
{
    c[1][1]=1;
    for(int i=1;i<=60;i++){
        c[i][1]=i;
        c[i][0]=1;
    }
    for(int i=1;i<=60;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            if(i==j)
                c[i][j]=1;
        }
    }

    memset(step,0,sizeof(step));
    step[1]=0;
    for(LL num=1;num<=60;num++){
        LL cur = num;
        LL ns=0;
        while(cur!=1){
            cur=ones(cur);
            ns++;
        }
        step[num]=ns;
    }
    //pre();
    msk();
    comb();
}
int main ()
{
    init();
    //cout<<c[5][2]<<endl;
    //for(int i=1;i<=10;i++)
        //cout<<i<<"  "<<step[i]<<endl;
    //cout<<cnt(1025,2)<<endl<<cnt(1023,2);
    while(scanf("%I64d%I64d%I64d",&l,&r,&x)==3 && x){
        Re=0;
        //for(LL i=1;i<=60;i++)
            //if(step[i]==x)
                //if(l<=i && i<=r)
                    //Re++;
        for(LL i=1;i<=60;i++){
            if(step[i]==x-1){
                Re+=cnt(r,i)-cnt(l-1,i);
            }
        }
        cout<<Re<<endl;
    }
    return 0;
}
