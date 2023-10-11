// Onegai no bug
// Author : Nyanpasuuuuu
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e2 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

ll f[N][N], dp[N][N], w[N], n, k;
vector<int>edge[N];
void dfs(int u,int pre)
{
    dp[u][0] = w[u];
    for(int v : edge[u]) if(v != pre)
    {
        dfs(v,u);
        FOR(i,1,n)f[u][i] = dp[v][i-1];
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                if(i + j>= k)maximize(f[u][min(i,j+1)],dp[u][i] + dp[v][j]);
            }
        }
        FOR(i,0,n)maximize(dp[u][i],f[u][i]);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    FOR(i,1,n)
        cin >> w[i];
    REP(i,1,n)
    {
        int x,y ;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    memset(f,0,sizeof f);
    dfs(1,1);
    ll ans = 0;
//    FOR(i,1,n)
//        FOR(j,1,3)cout << i  << " "<< j << " " << dp[i][j] << endl;
    FOR(i,0,n)maximize(ans,dp[1][i]);
    cout << ans;

}
