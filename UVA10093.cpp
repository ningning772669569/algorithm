#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int getnum(char c)
{
    if(c>='0' && c<='9')
        return c-'0';
    else if(c>='A' && c<= 'Z')
        return c-'A'+10;
    else
        return c-'a'+36;

}
int main ()
{
    char c;
    while((c=getchar())!=EOF){
        getchar();
        int re=getnum(c);
        if(re==0||re>=62)
            printf("such number is impossible!\n");
        else {
            printf("%d\n",re+1);
        }
    }
}
