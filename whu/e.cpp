#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int num[20];
int des;
int n;
int two[20];
int result;
vector<int> fitpos;

int check(int pos)
{
    //cout<<pos<<endl;
    vector<int> vec;
    vector<int> vv;
    set<int> s;s.clear();
    for(int i=1;i<=n;i++)
        if(pos & (1<<(i-1))){
            vec.push_back(num[i]);
        }
    s.insert(vec[0]);
    //cout<<"!!!"<<vec.size()<<endl;
    for(int i=1;i<vec.size();i++){
        vv.clear();
        //cout<<"##"<<s.size()<<endl;
        for(set<int>::iterator iter=s.begin();iter!=s.end();iter++){
            //int tep=*iter;
            vv.push_back((*iter)-vec[i]);
            vv.push_back((*iter)+vec[i]);
        }
        //cout<<"@@@  "<<vv.size()<<endl;
        for(int j=0;j<vv.size();j++)
            s.insert(vv[j]);
    }
    if( s.count(des) ){
        return 1;
    }
    //cout<<"!!!!!!!!!!!"<<endl;
    return 0;
}
void dfs(int num,int pos,int cur)
{
    //cout<<pos<<endl;
    if(pos==fitpos.size())
        return;
    result=max(result,num);
    if((fitpos[pos] & cur)==0){
        dfs(num+1,pos+1,cur|fitpos[pos]);
    }
    dfs(num,pos+1,cur);
}
int main ()
{
    two[0]=1;
    for(int i=1;i<=20;i++)
        two[i]=two[i-1]*2;
    int T;
    cin >>T;
    while(T--){
        //fitpos.clear();
        result=0;
        scanf("%d%d",&n,&des);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        fitpos.clear();
        for(int i=1;i<=two[n]-1;i++){
            if(check(i)){
                fitpos.push_back(i);
            }
        }
        cout<<fitpos.size()<<endl;
        for(int i=0;i<fitpos.size();i++)
            cout<<fitpos[i]<<"  ";
        cout<<" \n";
        dfs(0,0,0);
        cout<<result<<endl;
    }

}
