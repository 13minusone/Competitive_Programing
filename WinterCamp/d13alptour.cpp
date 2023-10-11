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
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

ll ans = -INF, a[N],dp[N], out[N];
int node, n;
vector<int>edge[N];
void dfs(int u, int pre)
{
    if(SZ(edge[u]) == 1)dp[u] = 0;
    for(int v : edge[u])if(v != pre)
    {
        dfs(v,u);
        maximize(dp[u],dp[v]);
    }
    dp[u] += a[u];
//    cout << u <<  "  " << dp[u] << endl;
}
void solve(int u, int pre)
{
    ii res = ii(-INF,-INF);
    ii node = ii(0,0);
    for(int v : edge[u])if(v != pre)
    {
        if(dp[v] > res.fi){
            res.se = res.fi;
            node.se = node.fi;
            node.fi = v;
            maximize(res.fi, dp[v]);
        }
        else if(maximize(res.se,dp[v]))node.se = v;
    }
    maximize(ans, max(res.fi + out[u], res.fi + res.se) + a[u]);
    maximize(ans, res.fi + a[u]);
    maximize(ans, out[u] + a[u]);
    for(int v : edge[u])if(v != pre)
    {
        maximize(out[v],out[u] + a[u]);
        if(v != node.fi)
            maximize(out[v], res.fi + a[u]);
        else
            maximize(out[v], res.se + a[u]);
        solve(v,u);
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        ans = -INF;
        FOR(i,1,n){
            cin >> a[i];
            maximize(ans,a[i]);
        }
        FOR(i,1,n-1)
        {
            register int x, y;
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        memset(dp,-0x3f,sizeof dp);
        dfs(1,1);
        memset(out,0,sizeof out);
        solve(1,1);
        cout << ans << endl;
    }

}

