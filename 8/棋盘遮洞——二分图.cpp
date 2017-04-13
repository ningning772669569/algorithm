#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 34
#define M N*N

int g[M][N], used[M], mat[M];
int match, m, n;

int find(int k)
{
    int i, j;

    for(i=1; i<=g[k][0]; i++)
    {
        j = g[k][i];
        if(!used[j])
        {
            used[j] = 1;
            if(!mat[j] || find(mat[j]))
            {
                mat[j] = k;
                return 1;
            }
        }
    }
    return 0;
}

void hungary()
{
    int i;
    for(i=1; i<=m*n; i++)
    {
        if(g[i][0] != -1 && g[i][0] != 0)
        {
            match += find(i);
            memset(used, 0, sizeof(used));
        }
    }
}

int main()
{
    int i, j;
    int k;
    int x, y;
    while(scanf("%d%d%d", &m, &n, &k)!=EOF){
    memset(g,0,sizeof(g));
    memset(used,0,sizeof(used));
    memset(mat,0,sizeof(mat));

    for(i=1; i<=k; i++)
    {
        scanf("%d%d", &x, &y);
        g[x+(y-1)*n][0] = -1;
    }
    for(i=1; i<=m*n; i++)
    {
        if(g[i][0] != -1)
        {
            //left

            if((i-1)%n >= 1 && g[i-1][0] != -1)
                g[i-1][++g[i-1][0]] = i;
            //right

            if(i%n != 0 && g[i+1][0] != -1)
                g[i+1][++g[i+1][0]] = i;
            //up

            if((i-(i%n)) / n >= 1 && g[i-n][0] != -1)
                g[i-n][++g[i-n][0]] = i;
            //down

            if((i-(i%n)+1) / n <= m && g[i+n][0] != -1)
                g[i+n][++g[i+n][0]] = i;
        }
    }
    match = 0;
    hungary();

    if(match == m*n-k)
        printf("YES\n");
    else printf("NO\n");

    }
    return 0;
}
