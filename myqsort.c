#include "stdio.h"
void qsort (int a[],int l,int r);
int a[]={1,2,7,4,9,23,56,3};
int main ()
{
    int i;
    qsort(a,0,7);
    for(i=0;i<8;i++)
        printf("%d ",a[i]);
}
void qsort (int a[],int l,int r)
{
    int i,j,mid,tep,c;
    i=l;
    j=r;
    mid=(i+j)/2;
    tep=a[mid];
    while(i<j){
        while(j>i){
            if(a[j]<tep)
            {
                break;
            }
            else{
                j--;
            }
        }
        while(j>i){
            if(a[i]>=tep){
                break;
            }
            else{
                i++;
            }
        }
        if(i<j){
            c=a[i];
            a[i]=a[j];
            a[j]=c;
        }
    }
    //a[i]=tep;
    if(i>l)
        qsort(a,l,i-1);
    if(j<r)
        qsort(a,i+1,r);

}
/*
int quicksort(vector<int> &v, int left, int right){
        if(left < right){
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && v[high] > key){
                                high--;
                        }
                        v[low] = v[high];
                        while(low < high && v[low] < key){
                                low++;
                        }
                        v[high] = v[low];
                }
                v[low] = key;
                quicksort(v,left,low-1);
                quicksort(v,low+1,right);
        }
}

寻找第k大的数
template<typename T>
int partition(T array[], int low, int high)
{
    T x = array[low];
    while(low < high)
    {
        while(low < high && array[high] <= x) --high;
        array[low] = array[high];
        while(low < high && array[low] >= x) ++low;
        array[high] = array[low];
    }
    array[low] = x;
    return low;
}    

/*返回a中第k大的元素，复杂度为O(n)*/                
void search(int *a, int i, int j, int k)               
{
    if(i <= j)
    {
        int q = partition(a, i, j);
        /*if a[q] is the key looking for, then print it*/
        if(q-i+1 == k)
        {
            /*be careful about the index*/
            cout<<"The "<<q+1<<"th min number is: "<<a[q]<<endl;
            return;
        }
        else if(q-i+1 < k)
        {
            /*look for the k-(q-i+1) th max number in [q+1, j]*/
            search(a, q+1, j, k-(q-i+1));
        }
        else
        {
            /*look for the k th max number in [i, q-1]*/
            search(a, i, q-1, k);    
        }
    }
}
