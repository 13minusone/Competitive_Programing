// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e2 + 5;
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, m, q,cost[N][N] , nextTo[N][N],c[N];
ll  dist[N][N];
signed main()
{

    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        memset(cost,0x3f,sizeof cost);
        FOR(i,1,m)
        {
            register int u, v, l;
            scanf("%d%d%d",&u,&v,&l);
            minimize(cost[u][v], l);
            minimize(cost[v][u], l);
        }
        FOR(i,1,n)cost[i][i] = 0;
        FOR(i,1,n)
            FOR(j,1,n)
                dist[i][j] = cost[i][j];
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n)
                    minimize(dist[i][j], dist[i][k] + dist[k][j]);
        FOR(i,1,n)
           FOR(j,1,n)if(i !=j){
                nextTo[i][j] = -1;
                FOR(k,1,n)
                    if(k != j && dist[i][k] + dist[k][j] == dist[i][j])
                        if(nextTo[i][j] == -1 || cost[nextTo[i][j]][j] > cost[k][j])
                            nextTo[i][j] = k;
            }
       // cout << nextTo[3][1] << endl;
        while(q--)
        {
            register int x;
            scanf("%d",&x);
            FOR(i,1,x)
                scanf("%d",&c[i]);
            ll res = 0;
            FOR(i,1,n)
            {
                ll ans = INF;
                int minCost = INF;
                FOR(j,1,x)
                    minimize(ans, dist[c[j]][i]);
                if(ans == 0)continue;
                FOR(j,1,x)
                    if(dist[c[j]][i] == ans)
                        minimize(minCost, cost[nextTo[c[j]][i]][i]);
                res += minCost;
                //cout << i << " " << minCost << endl;
            }
            printf("%lld ",res);
        }
    }

}

