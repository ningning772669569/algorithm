#include "cstdio"
#include "string"
#include "algorithm"
using namespace std;
void qsort (int num[],int front,int end)
{
	int middle;
	middle = front +(end - front )/2;
	int i, j;
	int tep;
	i=front;
	j=end;

	if(front  < end )
	{
		while(i<j)
		{
			while(i<j)
			{
				if(num[i]>num[middle])
					break;
				else
					i++;

			}
			while(i<j)
			{
				if(num[j]<num[middle])
					break;
				else
					j--;
			}
			if(i<j)
			{
				tep=num[i];
				num[i]=num[j];
				num[j]=tep;
			}
		}
		if(front<i)
			qsort(num,front,i-1);
		if(i<end)
			qsort(num,i+1,end);
	}

}
int main ()
{
	int i;
	int num[]={9,8,7,6,5,4,3,2,1,34,56,78,53};
	qsort(num,0,12);
	for(i=0;i<13;i++)
		printf("%d ",num[i]);

	return 0;
}
