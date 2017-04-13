#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 200001;
int mp[N];
int head[N];
int n, e;

void init()
{
    e = 0;
    memset( head, -1, sizeof(head) );
    memset( mp, 0, sizeof(mp) );
}

struct Edge
{
    int v, next, w;
} edge[N];

void addEdge( int u, int v, int w )
{
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}

void dfs( int u, int fa, int val )
{
    mp[val]++;
    for ( int i = head[u]; i != -1; i = edge[i].next )
    {
        int v = edge[i].v, w = edge[i].w;
        if ( v == fa ) continue;
        dfs( v, u, val ^ w );
    }
}

int main ()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d", &n);
        init();
        for ( int i = 1; i < n; i++ )
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge( u, v, w );
            addEdge( v, u, w );
        }
        dfs( 1, -1, 0 );
        int q;
        scanf("%d", &q);
        while ( q-- )
        {
            int tt;
            scanf("%d", &tt);
            ll ans = 0;
            if ( tt == 0 )
            {
                for ( int i = 0; i < N; i++ )
                {
                    ans += ( ll ) mp[i] * ( mp[i] + 1 ) / 2;
                }
            }
            else
            {
                for ( int i = 0; i < N; i++ )
                {
                    int tmp = tt ^ i;
                    if ( tmp >= N ) continue;
                    ans += ( ll ) mp[i] * mp[tmp];
                }
                ans = ans >> 1;
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
