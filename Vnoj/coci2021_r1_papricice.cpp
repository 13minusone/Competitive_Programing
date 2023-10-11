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

const int N = 1e6 + 5;
const int INF =1e9+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, sz[N];
vector<int>edge[N];
void dfs(int u, int pre)
{
    sz[u] = 1;
    for(int v : edge[u])if(v != pre)
    {
        dfs(v, u);
        sz[u] += sz[v];
    }
}
multiset<int>ms1,ms2;
int ans = INF;
void check(int u)
{
    if(SZ(ms1) > 0) {
        for(int d = -1; d <= 1; d++) {
            int x = (sz[u] + n + d) / 2;
            auto it = ms1.lower_bound(x);
            if(it != ms1.end()) {
                minimize(ans, max({sz[u], *it - sz[u], n - *it}) - min({sz[u], *it - sz[u], n - *it}));
            }
            if(it != ms1.begin()) {
                --it;
                minimize(ans, max({sz[u], *it - sz[u], n - *it}) - min({sz[u], *it - sz[u], n - *it}));
            }
        }
    }
    if(SZ(ms2) > 0) {
        for(int d = -1; d <= 1; d++) {
            int x = (n - sz[u] + d) / 2;
            auto it = ms2.lower_bound(x);
            if(it != ms2.end()) {
                minimize(ans, max({sz[u], *it , n - *it - sz[u]}) - min({sz[u], *it, n - *it - sz[u]}));
            }
            if(it != ms2.begin()) {
                --it;
                minimize(ans, max({sz[u], *it , n - *it - sz[u]}) - min({sz[u], *it, n - *it - sz[u]}));
            }
        }
    }
}
void solve(int u, int pre)
{
    check(u);
   // cout << u << " " << ans << endl;
    ms1.insert(sz[u]);
    for(int v : edge[u])
        if(v !=  pre)
            solve(v,u);
    ms1.erase(ms1.find(sz[u]));
    ms2.insert(sz[u]);
    check(u);
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
        FOR(i,1,n-1)
        {
            register int x, y;
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        dfs(1,1);
        solve(1,1);
        cout << ans << endl;
    }

}

