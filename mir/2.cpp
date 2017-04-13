#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> psi;
int N,M;
set<string> al;
set<string> de;
int global=0;
int main ()
{
    cin >>N>>M;
    for(int inum=1;inum<=N;inum++){
        string choice;
        string ip;
        cin >>choice;
        cin >>ip;
        //cout<<"  ip   ="<<ip<<endl;
        int pos;
        int num[10];
        int numpos=1;
        int flag=0;
        for(pos=0;pos<ip.size();pos++){

            if(ip[pos]=='.'){
                int lastpos=pos-1;
                //cout<<lastpos<<"   "<<pos<<endl;
                while(lastpos>=0 && ip[lastpos]!='.')
                    lastpos--;
                string teps=ip.substr(lastpos+1,pos-lastpos-1);
                //cout<<lastpos<<"   "<<pos<<endl;
                //cout<<"!!!   "<<teps<<endl;
                num[numpos]=atoi(teps.c_str());
                numpos++;
            }
            if(ip[pos]=='/'){
                flag=1;
                int lastpos=pos;
                while(lastpos>=0 && ip[lastpos]!='.')
                    lastpos--;
                string teps=ip.substr(lastpos+1,pos-lastpos-1);
                num[numpos]=atoi(teps.c_str());
                numpos++;
                string ttep=ip.substr(pos+1,ip.size()-pos-1);
                //cout<<"!!!   "<<ttep<<endl;
                num[numpos]=atoi(ttep.c_str());
                if(num[5]==0)
                    global=1;
            }

        }
        if(!flag){
            int pos=ip.size()-1;
            while(pos>=0&&ip[pos]!='.')
                pos--;
            string tep=ip.substr(pos+1,ip.size()-pos-1);
            num[4]=atoi(tep.c_str());
        }
        string str(32,'0');
        for(int i=0;i<=3;i++){
            int n=num[i+1];
            for(int j=8*i+7;j>8*i-1;j--){
                str[j]=n%2+'0';
                n/=2;
            }
        }
        if(flag){
            for(int i=num[5];i<=31;i++){
                str[i]='0';
            }
        }

        if(choice[0]=='a')
            al.insert(str);
        else
            de.insert(str);
    }
    for(int inum=1;inum<=M;inum++){
        string ip;
        cin >>ip;
        int pos;
        int num[10];
        int numpos=1;
        for(pos=0;pos<ip.size();pos++){
            if(ip[pos]=='.'){
                int lastpos=pos-1;
                while(lastpos>=0 && ip[lastpos]!='.')
                    lastpos--;
                string teps=ip.substr(lastpos+1,pos-lastpos-1);
                num[numpos]=atoi(teps.c_str());
                numpos++;
            }
        }
        pos=ip.size()-1;
        while(pos>=0&&ip[pos]!='.')
            pos--;
        string tep=ip.substr(pos+1,ip.size()-pos-1);
        num[4]=atoi(tep.c_str());
        string fstr(32,'0');
        for(int i=0;i<=3;i++){
            int n=num[i+1];
            for(int j=8*i+7;j>8*i-1;j--){
                fstr[j]=n%2+'0';
                n/=2;
            }
        }
        int flag=0;
        int low=1;
        if(global)
            low=0;
        for(int i=32;i>=low;i--){
            string ffstr;
            if(i>0)
                ffstr=fstr.substr(0,i)+string(32-i,'0');
            else
                ffstr=string(32,'0');

            if(de.count(ffstr)){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
            if(al.count(ffstr)){
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<"YES"<<endl;
        }
    }

    return 0;
}
