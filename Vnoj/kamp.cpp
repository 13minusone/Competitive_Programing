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

const int N = 5e5 + 5;
const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, q, sz[N];
bool special[N];
ll dist[N], furthest[N], distout[N], furthestout[N], ans[N];
vector<ii>edge[N];
void dfs(int u, int pre)
{
    furthest[u] = -MOD;
    if(special[u])furthest[u] = 0;
    for(ii v : edge[u])if(v.fi != pre)
        {
        dfs(v.fi,u);
        sz[u] |= sz[v.fi];
        dist[u] += (dist[v.fi] + 1LL * sz[v.fi] * v.se);
        maximize(furthest[u], furthest[v.fi] + v.se);
        }
       sz[u] |= special[u];
    cout << u << " " << sz[u] << " " << furthest[u] << endl;
}
void solve(int u, int pre)
{
    ii maxx = ii(0,0);
    maxx.fi = furthestout[u];
    ll sum = distout[u];
    //cout << u <<  " " << distout[u] << " " << max(furthest[u], furthestout[u]) << endl;
    ans[u] = 1LL *(distout[u] + dist[u] - max(furthest[u], furthestout[u])) * 2 + max(furthest[u], furthestout[u]);
    for(ii v : edge[u])
        if(v.fi != pre)
        {
            if(maxx.fi < furthest[v.fi]){
                maximize(maxx.se, maxx.fi);
                maxx.fi = furthest[v.fi];
            }
            else maximize(maxx.se, furthest[v.fi]);
            sum += (dist[v.fi] + (1LL * sz[v.fi] * v.se));
        }
    for(ii v : edge[u]) if(v.fi != pre)
    {
        furthestout[v.fi] = (furthest[v.fi] == maxx.fi ? maxx.se : maxx.fi);
        distout[v.fi] = sum - (dist[v.fi]);
        solve(v.fi,u);
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
        cin >> n >> q;
        REP(i,1,n)
        {
            register int u, v, w;
            cin >> u >> v >> w;
            edge[u].pb(ii(v,w));
            edge[v].pb(ii(u,w));
        }
        FOR(i,1,q)
        {
            register int x;
            cin >> x;
            special[x] = 1;
        }
        dfs(1,1);
        solve(1,1);
        FOR(i,1,n)cout << ans[i] << endl;
    }

}
