#include<bits/stdc++.h>
using namespace std;
#define task "bedao_g10_holiday"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define BIT(i) ((1LL)<<(i))
#define GETBIT(x,i) (((x)>>(i))&1)
#define TURNOFF(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define LOG 21
#define MASK(i) ((1LL)<<(i))
#define EL cout << "\n"
#define FU(i, a, b) for(int i=a; i<=b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, x) for(int i=0; i<x; i++)
const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
const int base = 31;
const ll INF = 1e18 + 7;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
template<class X, class Y> bool maximize(X &x, Y y){ if (x < y) {x = y; return true;} return false;};
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y) {x = y; return true;} return false;};
//void add(int &x, int y) { x += y; if (x>=mod) x-=mod;}
//void sub(int &x, int y) { x -= y; if (x<0) x+=mod;}
int calPw(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if (y&1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
struct FenwickTree
{
    int n;
    vector<ll> v;
    FenwickTree(int _n=0)
    {
        n = _n;
        v.assign(n+5, 0);
    }
    void update(int x, ll c)
    {
        for(; x<=n; x+=x&-x) v[x] += c;
    }
    ll get(int x)
    {
        ll res = 0;
        for(; x>0; x-=x&-x) res += v[x];
        return res;
    }
} bit;
int n, q, d;
int high[MAX], par[MAX], tin[MAX], tout[MAX], lg2[2*MAX], num[MAX], node[MAX], lab[MAX * 2], rmq[2 * MAX][LOG+3];
ll val[MAX];
vector<ii> adj[MAX];
void read()
{
    cin >> n >> q;
    FU(i, 2, n)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(ii(v, w));
        adj[v].pb(ii(u, w));
    }
}
int Time = 0, cnt = 0;
void dfs(int u, int c)
{
    tin[u] = ++Time;
    lab[++cnt] = u;
    num[u] = cnt;
    for(auto [v, c]: adj[u]) if (v!=par[u])
    {
        high[v] = high[u] + 1;
        par[v] = u;
        dfs(v, c);
        lab[++cnt] = u;
    }
    tout[u] = Time;
    bit.update(tin[u], c);
    bit.update(tout[u] + 1, - c);
}
#define MIN(x, y) (high[x] < high[y] ? (x) : (y))

void preRMQ()
{
    for (int i = 1; i <= cnt; i++)
        rmq[i][0] = lab[i];
    for (int j = 1; BIT(j) <= cnt; j++)
        for (int i = 1; i <= cnt - BIT(j) + 1; i++)
            rmq[i][j] = MIN(rmq[i][j - 1], rmq[i + BIT(j - 1)][j - 1]);
    for (int i = 0; i <= cnt; i++)
    {
        lg2[i] = 0;
        while (BIT(lg2[i]) <= i)
            lg2[i]++;
        lg2[i]--;
    }
}

int LCA(int u, int v)
{
    int l = num[u];
    int r = num[v];
    if (l > r)
        swap(l, r);
    int k = lg2[r - l + 1];
    return MIN(rmq[l][k], rmq[r - BIT(k) + 1][k]);
}
void sol()
{
    bit = FenwickTree(n+1);
    dfs(1, 0);
    preRMQ();
    //cout << bit.get(tin[16])+ bit.get(tin[7]) - 2 * bit.get(tin[2]); EL;
    //cout << LCA(8, 5);
    //return;
    //cout << bit.get(tin[6]) << " " << bit.get(tin[2]), EL;
    while(q--)
    {
        cin >> d;
        int u;
        ll res = 0;
        FU(i, 1, d)
        {
            cin >> node[i];
            if(val[node[i]] == 0) val[node[i]] = bit.get(tin[node[i]]);
            if (maximize(res, val[node[i]] + high[node[i]])) u = node[i];
        }
        ll ans = 0;
        FU(i, 1, d)
        {
            int lca = LCA(u, node[i]);
            if(val[lca] == 0) val[lca] = bit.get(tin[lca]);
            maximize(ans, res + val[node[i]] + high[node[i]] - 2 * high[lca] - 2LL * val[lca]);
        }
        cout << ans, EL;
    }
}
signed main()
{
    fastio();
    init();
    int T = 1;
    //cin >> T;
    while(T--)
    {
        read();
        sol();
    }
}
