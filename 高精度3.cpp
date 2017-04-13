#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
//#include "string.h"
#define maxsize 1000
using namespace std;
struct bign{
    int s[maxsize];
    int len;
    bign(){memset(s,0,sizeof(s));}
    bign(const char * num){
        len=strlen(num);
        for(int i=0;i<len;i++)
        s[i]=num[len-i-1]-'0';

    }
    bign(int num){
        char str[maxsize];
        sprintf(str,"%d",num);
        *this=str;

    }
    bign operator =(const char * num){
        len=strlen(num);
        for(int i=0;i<len;i++)
            s[i]=num[len-i-1]-'0';
        return * this;
    }
    bign operator =(int num){
        char str[maxsize];
        sprintf(str,"%d",num);
        *this=str;
        return * this;
    }
    string str() const{
        string re="";
        for(int i=0;i<len;i++)
            re=char(s[i]+'0')+re;
        if(re=="")
            re="0";
        return re;
    }
    bign operator +(const bign &b) const
    {
        bign re;
        re.len=0;
        int c=0;
        int store;
        for(int i=0;i<max(len,b.len);i++){
            if(i<len)
                store+=s[i];
            if(i<b.len)
                store+=b.s[i];
            re.s[i]=store%10;
            c=store/10;


        }
         return re;
    }
};

int main ()
{

}
