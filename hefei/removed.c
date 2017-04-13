#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
template<class T>
int bsearch(T c[],int n,T a)
{

    int l=1, r=n;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if( a > c[mid] && a <= c[mid+1] )
            return mid+1; // >&&<= 换为: >= && <
        else if( a < c[mid] )
           r = mid-1;
        else l = mid+1;
    }

}

template<class T>
int LIS(T a[], int n)
{

    int i, j, size = 1;
    T *c=new T[n+1];
    int *dp=new int[n+1];
    c[1] = a[1]; dp[1] = 1;

    for(i=2;i<=n;++i)
    {
        if( a[i] <= c[1] ) j = 1;// <= 换为: <
        else if( a[i] >c[size] )
            j=++size;   // > 换为: >=
        else
            j = bsearch(c, size, a[i]);
        c[j] = a[i]; dp[i] = j;
    }
    return size;

}
int main ()
{


}
