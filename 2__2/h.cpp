#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
char firstname[202][80];
char lastname[202][80];
int n,k;
struct Tire{
    int is_str;
    int next;
};
struct Tire tire[500000][36];
int alloc;
int getnum(char c)
{
    if(c>='a'&&c<='z'){
        return c-'a';
    }
    else {
        return c-'0'+26;
    }
}
void insert(char * s)
{
    int cur=0;
    int len=strlen(s);
    len=min(len,k);
    for(int i=0;i<len;i++){
        int num=getnum(s[i]);
        if(tire[cur][num].next==-1){
            tire[cur][num].next=++alloc;

        }
        if(i=len-1){
            tire[cur][num].is_str=1;

        }
        cur=tire[cur][num];
    }
}
int research(char * s)
{
    int cur=0;
    len=strlen(s);
    for(int i=0;i<len;i++){
        int num=getnum(s[i]);
        if(tire[cur][num].next==-1) return false;
        if(i==len-1){
            if(tire[cur][num].is_str==1)   return true;
            return false;
        }
        cur=tire[cur][num].next;
    }
}
void init()
{
    memset (tire,-1,sizeof(tire));
    alloc=0;
}
int main ()
{
    while (1){

        scanf("%d %d",&n,&k);
        if(n==0&&k==0){
            break;
        }

        init();
        for(int i=1;i<=n;i++){
            scanf("%s",firstname[i]);
            char s[80];
            scanf("%s",s);
            char c;
            getchar();
            if(c==' ')
                scanf("%s",lastname[i]);
            else
                strcpy(last[i],s);
        }
    }
}
