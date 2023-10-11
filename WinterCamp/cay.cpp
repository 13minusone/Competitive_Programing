/// Do the solution on the paper first
#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
#define task "cay"
#define int long long
#define rep(i, n) for(int i = 0;i < n;++i)
#define FOR(i, l, r) for(int i = l;i <= r;++i)
#define FOD(i, r, l) for(int i = r;i >= l;--i)
#define dem(x) __builtin_popcount(x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define SZ(x) (int)((x).size())
#define fi first
#define se second
typedef pair<int,int> ii;
//const int dx[4] = {-1, 0, 1, 0};
//const int dy[4] = {0, -1, 0, 1};
//const int base = 311;
//const int mod = 1e9 + 7;
const int N = 3e5 + 5;
int dp[N][55], n, k, c[N], f[N][55], res, g[N][55];
vector<ii> a[N];
void dfs(int u, int p = 0){
    for(auto x : a[u]){
        int v = x.fi, w = x.se;
        if(v == p) continue;
        dfs(v, u);
        for(int i = 0; i < w; ++i) f[u][i] += dp[v][0];
        for(int i = 0; i <= k-w; ++i) f[u][i+w] += dp[v][i];
    }

    for(auto x : a[u]){
        int v = x.fi, w = x.se; if (v == p) continue;
        FOR(i, 0, k) g[u][i] = dp[u][i];

        for(int i = 0; i + w <= k; ++i){
            int j = max(i + w, k - i - w);
            maxx(g[u][i+w], f[u][j] - dp[v][j-w] + dp[v][i]);
        }

        maxx(res, c[u] + dp[v][k-w]);
        FOR(i, 0, k) dp[u][i] = g[u][i];
    }
    dp[u][0] = c[u];
    FOD(i, k, 0)maxx(dp[u][i], dp[u][i+1]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> n >> k;
    FOR(i, 1, n)cin >> c[i];
    FOR(i, 2, n){
        int u, v, c; cin >> u >> v >> c;
        a[u].pb(ii(v, c)); a[v].pb(ii(u, c));
    }
    dfs(1);
    FOR(i, 1, n)FOR(j, 0, k)maxx(res, dp[i][j]);
    cout << res;
}
