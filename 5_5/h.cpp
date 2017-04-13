#include "cstring"
#include "cstdio"
#include "algorithm"
#include "iostream"
using namespace std;
int n;
char word[50];
int main ()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%s",word);
            int len=strlen(word);
            if(word[len-1]=='x'||word[len-1]=='s'||word[len-1]=='o'||(word[len-1]=='h'&&word[len-2]=='c')){
                strcat(word,"es");
            }
            else if(word[len-1]=='f'||(word[len-1]=='e'&&word[len-2]=='f')){
                if(word[len-1]=='f'){
                    word[len-1]='v';
                    strcat(word,"es");
                }
                else{
                    word[len-2]='v';
                    strcat(word,"s");
                }
            }
            else if(word[len-1]=='y'){
                word[len-1]='i';
                strcat(word,"es");
            }
            else{
                strcat(word,"s");
            }
            printf("%s\n",word);
        }
    }
}
