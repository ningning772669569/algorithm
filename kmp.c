#include "stdio.h"
#include "stdlib.h"
#include "string,h"
#define MAX 100
#define MAX_LENGTH 1000
int next[MAX];
void get_next (int next[],char s[])
{
	int i,j;
	i=0;
	j=-1;
	next[0]=-1;
	while (s[i]!='\0'){
		if(j==-1||s[i]==s[j]){
			i++;
			j++;
			next[i]=j;
		}
		else
			j=next[j];
	}	
}

int kmp (char* base,char * s)
{
	int i,j;
	i=0;
	j=0;
	while(base[i]!='\0'&&s[j]!='\0'){
		if(j==-1||base[i]==s[j]){
			++i;
			++j;
		}
		else{
			j=next[j];
		}	
	}
	if(s[j]=='\0'){
		return i-j;
	}
	else 
		return -1;
}
int main ()
{
	char s[MAX];
	char base[MAX_LENGTH];
	int result;
	printf("输入模式串\n");
	scanf("%s",s);
	printf("输入匹配串\n");
	scanf("%s",base);
	get_next(next,s);
	if(result=kmp(base,s)!=-1)
		printf("结果是%d\n",result);
	else
		printf("no result "); 
	return 0;
}
