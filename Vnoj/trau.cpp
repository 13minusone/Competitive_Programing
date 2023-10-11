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
#define LOG 20
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
int high[MAX], par[MAX], tin[MAX], tout[MAX], lg2[2*MAX], num[MAX], node[MAX], lab[MAX * 2], rmq[2 * MAX][LOG+2];
ll dp[MAX];
bool used[MAX];
vector<ii> adj[MAX];
vector<pair<int, ll>> dsk[MAX];
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
    if (u == 1)
    {
        bit.update(tin[u], c);
        bit.update(tout[u] + 1, - c);
    }
    else
    {
        bit.update(tin[u], c + 1);
        bit.update(tout[u] + 1, - c - 1);
    }
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

//int LCA(int u, int v)
//{
//    if (high[u] < high[v]) swap(u, v);
//    int k = high[u] - high[v];
//    FD(i, LOG, 0) if (k & (1 << i)) u = par[u][i];
//    if (u == v) return u;
//    FD(i, LOG, 0) if (par[u][i] != par[v][i])
//    {
//        u = par[u][i];
//        v = par[v][i];
//    }
//    return par[u][0];
//}
int LCA(int u, int v)
{
    int l = num[u];
    int r = num[v];
    if (l > r)
        swap(l, r);
    int k = lg2[r - l + 1];
    return MIN(rmq[l][k], rmq[r - BIT(k) + 1][k]);
}
bool checkInside(int u, int v)
{
    return tin[v] >= tin[u] && tin[v] <= tout[u];
}
ll ans = 0;
void calDp(int u)
{
    dp[u] = 0;
    ll mx1 = -INF , mx2 = -INF;
    for(pair<int, ll> tmp: dsk[u])
    {
        int v = tmp.fi; ll w = tmp.se;
        calDp(v);
        if (mx1 < dp[v] + w)
        {
            mx2 = mx1;
            mx1 = dp[v]+ w;
        }
        else maximize(mx2, dp[v] + w);
        dp[u] = max(dp[u], dp[v] + w);
    }
    ans = max(ans, max(mx1, mx2));
    ans = max(ans, mx1 + mx2);
}
void sol()
{
    bit = FenwickTree(n+1);
    dfs(1, 0);
    preRMQ();
    //cout << LCA(8, 5);
    //return;
    //cout << bit.get(tin[6]) << " " << bit.get(tin[2]), EL;
    while(q--)
    {
        cin >> d;
        FU(i, 1, d)
        {
            cin >> node[i];
            used[node[i]] = true;
        }
        sort(node+1, node+d+1, [&](const int &u, const int &v)
             {
                 return tin[u] < tin[v];
             });
        FU(i, 1, d-1)
        {
            int lca = LCA(node[i], node[i+1]);
            //cout << node[i] << " " << node[i+1] << " " << lca, EL;
            if (!used[lca])
            {
                node[++d] = lca;
                used[lca] = true;
            }
        }
        sort(node+1, node+d+1, [&](const int &u, const int &v)
             {
                 return tin[u] < tin[v];
             });
        ////FU(i, 1, d) cout << node[i] << " "; EL;
        stack<int> st; st.push(node[1]);
        FU(i, 2, d)
        {
            while(st.size() && !checkInside(st.top(), node[i])) st.pop();
            dsk[st.top()].pb({node[i], bit.get(tin[node[i]]) - bit.get(tin[st.top()])});
            //cout << st.top() << " " << node[i] << " " << bit.get(tin[node[i]]) - bit.get(tin[st.top()]), EL;
            st.push(node[i]);
        }
        ans = 0;
        calDp(node[1]);
        cout << ans; EL;
        FU(i, 1, d)
        {
            dsk[node[i]].clear();
            used[node[i]] = false;
        }
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
