#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
const int MAX = 100010;
int  p[2*MAX];
int str[2*MAX], newstr[2*MAX];
int sum[MAX];
int m,n;
void change()
{
     int i;
     newstr[0] = '@';
     newstr[1] = '#';
     for (i = 0; i <n; i++){
         newstr[2*i + 2] = str[i];
         newstr[2*i + 3] = '#';
     }
     newstr[2*n + 2] = '\0';
     return ;
}


void Manacher()
{
     int i, j, id, maxid = 0, ans = 1;
     n = 2 * n + 2;
     for (i = 0; i < n; i++){
         if (maxid > i){
             p[i] = min(p[2*id - i], maxid - i);
         }
         else{
              p[i] = 1;
         }
         while (newstr[i+p[i]] == newstr[i-p[i]])
                p[i]++;
         if (p[i] + i > maxid){
             maxid = p[i] + i;
             id = i;
         }
         if (ans < p[i])
             ans = p[i];
     }

     for (i = id, j = 0; i < id + ans; i++){
          if (newstr[i] != '#'){
              str[j] = newstr[i];
              j++;
          }
     }
     str[id+ans] = '\0';
     ///cout << ans - 1 << " " << str << endl;
     //return ;
}

void search(int l,int r)
{
    long long re=0;
    l-=1;
    for(int i=l;i<=r;i++){
        int len1=min(i-l,(p[i]-1)/2);
        int len2=min((p[i]-1)/2,r-i);
        int len=min(len1,len2);
        if(!len)
            re+=sum[i+len]-sum[i-len];
        else
            re+=str[i];
    }
    printf("%d\n",re);
}
int main()
{
    sum[0]=0;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
            scanf("%d",&str[i]);
            sum[i]=(i==0?str[i]:sum[i-1]+str[i]);
    }

    change();
    Manacher();
    int pos=0;
    for(int i=1;i<=n;i++){
        p[pos]=p[2*i]-1;
    }
    int l,r;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&l,&r);
        search(l,r);

    }
    return 0;


}
