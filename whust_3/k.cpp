#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL _count;
char s[67];
LL hnum[67];
void hanoi (int n,char x,char y,char z);
int main ()
{
    memset(hnum,0,sizeof(hnum));
    while(1){
        scanf("%s",s);
        if(strcmp("X",s)==0)
            break;
        _count =0;
        int len=strlen(s);
        int num[3]={0,0,0};
        for(int i=0;i<len;i++){
            num[s[i]-'A']++;
        }
        if(num[0])
        hanoi(num[0],'x','z','y');
        if(num[2])
        hanoi(num[2],'z','x','y');
        printf("%I64d\n",_count);
    }
}
void hanoi (int n,char x,char y,char z)

{
	if(n==1)
		++_count;
	else{
		hanoi(n-1,x,z,y);
		++_count;
		hanoi(n-1,y,x,z);
	}
}
