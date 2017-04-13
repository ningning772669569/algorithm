#include "stdio.h"
void merge_sort (int front,int back,int *s);
int store[20];

int main ()
{
	int i;
	int a[]={1,23,56,86,43,78,56,87,54};
	merge_sort(0,9,a);
	for(i=0;i<9;i++){
		printf(" %d ",a[i]);
	}
	return 0;
}
void merge_sort (int front,int back,int *s)
{
	int p=front;
	if(back-front>1){
		int mid=front+(back-front)/2;
		int q=mid;
		int i=front;
		merge_sort(front,mid,s);
		merge_sort(mid,back,s);
		while(p<mid||q<back){
			if(q>=back||(p<mid&&s[p]<s[q])){
				store[i++]=s[p++];
			}
			else{
				store[i++]=s[q++];
			}
		}
		for(i=front;i<back;i++){
			s[i]=store[i];
		}	
	}

}
