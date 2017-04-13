#include "cstdio"
#include "cstring"
#define MAX 1000001
using namespace std;

int  f[MAX];
char s[MAX];
int main ()
{
    int n;
    int k=1;
    while((scanf("%d",&n)!=EOF)&&n){
        scanf("%s",s);
        f[0]=f[1]=0;
        for(int i=1;i<n;i++){
            int j=f[i];
            while(j&&s[i]!=s[j]) j=f[j];
            if(s[i]==s[j])   f[i+1]=j+1;
            else            f[i+1]=0;
        }
        printf("Test case #%d\n",k++);
        for(int i=2;i<=n;i++){
            if(f[i]&&(i%(i-f[i])==0))
                if(i/(i-f[i])>1)
                printf("%d %d\n",i,i/(i-f[i]));
        }
        printf("\n");
    }
    return 0;
}
