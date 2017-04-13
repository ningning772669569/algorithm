#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MAX 1000
char word[MAX][20];
char sorted[MAX][20];
int main ()
{
    int n=0;
    int i;
    int find;
    while(1){
        scanf("%s",word[n]);
        if(word[n][0]=='*'){
            break;
        }
        n++;
    }
    qsort(word,n,sizeof(word[0]),cmp_string);
    for(i=0;i<n;i++){
        strcpy(sorted[i],word[i]);
        qsort(sorted[i],strlen(word[i]),sizeof(char),cmp_char);
    }
    char s[20];
    while(sacnf("%s",s)==1){
        qosrt(s,strlen(s),sizeof(char),cmp_char);
        find =0;
        for(i=0;i<n;i++){
            if(strcmp(s,sorted[i])==0)
                {
                    printf("%s ",word[i]);
                    find=1;
                }
        }
        if(!find){
            printf(":(");

        }
    }
    return 0;

}
int cmp_word(const void  *word1,const void  *word2)
{
    char * a=(char *)word1;
    char * b=(char *)word2;
    return strcmp(a,b);
}
int cmp_char (const void  *a,const void *b)
{
    char *_a=(char *)a;
    char *_b=(char *)b;
    return *_a-*_b;
}
