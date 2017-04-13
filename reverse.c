#include "string.h"
#include <stdio.h>
void reverse(char[]);
main()
{
    int T;
    int N;
    scanf("%d",&T);
    char result[T][1000];
    char tep[11];
    int i,j;
    for(i=1;i<=T;i++){
        for(j=1;j<=N;j++){
            scanf("%s",tep);
            reverse(tep);
            strcat(result[i],tep);
        }
    }
    for(i=1;i<=T;i++){
        printf("%s\n",result[i]);
    }
    return 0;

}
void reverse(char s[])
{
  int i, j, c, n=0;
  while(s[n]!='\0')
  n++;

  for(i=0,j=n-1;i<j;i++,j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
