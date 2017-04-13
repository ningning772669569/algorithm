#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long LL;
int N;
char sstr[105][105];
char estr[105][105];
char key[105];
int get(char c)
{
    return c-'A';
}
int getkey(int nn,int len)
{

    memset(key,0,sizeof(key));
    int pos=len;
    int ll=strlen(sstr[nn]);
    if(ll<=len){
        for(int i=0;i<ll;i++){
            key[i]=(get(estr[nn][i])+26-get(sstr[nn][i]))%26+'A';
        }
        return 1;
    }
    int flag=1;
    while(pos<ll){
        int tep;
        for(tep=pos;tep<pos+len && tep<ll;tep++){
            if(get(estr[nn][tep]) != (get(sstr[nn][tep]+get(estr[nn][tep-len])))%26){
                flag=0;
                break;
            }
        }
        if(flag==0)
            break;
        pos=tep;
    }
    if(flag)
    {
        for(int i=0;i<len;i++){
            key[i]=(get(estr[nn][i])+26-get(sstr[nn][i]))%26+'A';
        }
        return 1;
    }
    return 0;
}
int check(int pos)
{
    char str1[109];
    char str2[109];
    //printf("%s\n",key);
    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));
    strcpy(str1,sstr[pos]);
    strcpy(str2,estr[pos]);
    int flag=1;
    int ll=strlen(str1);
    for(int i=0;i<strlen(key)&&i<ll;i++){
        if(get(key[i])!=(get(str2[i])+26-get(str1[i]))%26){
            flag=0;
            break;
        }
    }
    return flag;
}
int main ()
{
    while(scanf("%d",&N) && N){
        memset(sstr,0,sizeof(sstr));
        memset(estr,0,sizeof(estr));
        for(int i=1;i<=N;i++){
            scanf("%s%s",sstr[i],estr[i]);

            }
        int maxlen=100;
        int success=0;
        for(int len=1;len<maxlen;len++){
            int flag=1;
            int tepsuccess=1;
            for(int pos=1;pos<=N;pos++){
                int re=getkey(pos,len);
                if(re==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag){
                //cout<<len<<endl;
                int des=1;
                int M=strlen(sstr[1]);
                for(int i=2;i<=N;i++){
                    if(strlen(sstr[i])>M){
                        M=strlen(sstr[i]);
                        des=i;
                    }
                }
                getkey(des,len);

                for(int i=1;i<=N;i++){
                    int re=check(i);
                    if(re==0){
                        tepsuccess=0;
                        break;
                    }
                }
                if(tepsuccess==0)
                    break;
                else{
                    success=1;
                    break;
                }
            }
        }
        if(success)
            printf("%s\n",key);
        else
            printf("Impossible\n");
    }
    return 0;
}
