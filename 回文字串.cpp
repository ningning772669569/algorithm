#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[2009000];
char str[2009000];
int main ()
{
    int T;
    cin >>T;
    while(T--){
        string s;
        cin >>s;
        memset(dp,0,sizeof(dp));
        //string str("@#");
        //for(int i=0;i<s.size();i++)
            //str=str+s[i]+string("#");
        //str+="!";
        memset(str,0,sizeof(str));
        str[0]='&';
        str[1]='#';
        int len=2;
        for(int i=0;i<s.size();i++){
            str[len++]=s[i];
            str[len++]='#';
        }
        int mid=0;
        int mx=0;
        for(int pos=1;pos<=len;pos++){
            if(mx>pos){
                dp[pos]=min(mx-pos+1,dp[2*mid-pos]);
            }
            else
                dp[pos]=1;
            while(str[pos+dp[pos]]==str[pos-dp[pos]])
                dp[pos]++;
            if(pos+dp[pos]-1>mx){
                mx=pos+dp[pos]-1;
                mid=pos;
            }
        }
        int re=0;
        for(int i=0;i<len;i++)
            re=max(re,dp[i]);
        cout<<re-1<<endl;
    }
    return 0;
}
