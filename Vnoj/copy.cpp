/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "test"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define mp make_pair
#define MASK(x, i) (((x) >> (i))&1)
typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if (fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(1e5) + 100;
const ll INF = 1e18;
int n, q;
struct Query
{
    int u, v, t;
    Query(){}
    Query(int _u, int _v, int _t)
    {
        u = _u;
        v = _v;
        t = _t;
    }
};
vec<Query> queries;
struct State
{
    int u, parU, v, parV;
    State(){}
    State(int _u, int _parU, int _v, int _parV)
    {
        u = _u;
        v = _v;
        parU = _parU;
        parV = _parV;
    }
};
struct DisjointsSet
{
    vec<int> par;
    DisjointsSet(int n = 0)
    {
        par.assign(n + 5, -1);
    }
    int root(int u) { return (par[u] < 0 ? u : root(par[u]));}
    State join(int u, int v)
    {
        State res;
        if(-par[u] < -par[v]) swap(u, v);
        res = State(u, par[u], v, par[v]);
        par[u] += par[v];
        par[v] = u;
        return res;
    }
} dsu;
int ans[N];
void init()
{
    cin >> n >> q;
    queries.pb(Query(0, 0, 0));
    for(int i = 1; i <= q; i++)
    {
        int u, v, t;
        cin >> t >> u >> v;
        if(u > v) swap(u, v);
        queries.pb(Query(u, v, t));
    }
}
map<ii, int> pos;
stack<int> st[N];
int lef[N], rig[N];
void solve(int l, int r)
{
    if(l == r)
    {
        if(queries[l].t == 3)
        {
            if(dsu.root(queries[l].u) == dsu.root(queries[l].v))
                ans[l] = 1;
            else
                ans[l] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    stack<State> st;
    for(int i = mid + 1; i <= r; i++) if(queries[i].t == 2 && lef[i] < l)
    {
        int x = queries[i].u;
        int y = queries[i].v;
        int u = dsu.root(x);
        int v = dsu.root(y);
        if(u == v) continue;
        st.push(dsu.join(u, v));
    }
    solve(l, mid);
    while(!st.empty())
    {
        int u = st.top().u;
        int v = st.top().v;
        int parU = st.top().parU;
        int parV = st.top().parV;
        dsu.par[u] = parU;
        dsu.par[v] = parV;
        st.pop();
    }
    for(int i = l; i <= mid; i++) if(queries[i].t == 1 && rig[i] > r)
    {
        int x = queries[i].u;
        int y = queries[i].v;
        int u = dsu.root(x);
        int v = dsu.root(y);
        if(u == v) continue;
        st.push(dsu.join(u, v));
    }
    solve(mid + 1, r);
    while(!st.empty())
    {
        int u = st.top().u;
        int v = st.top().v;
        int parU = st.top().parU;
        int parV = st.top().parV;
        dsu.par[u] = parU;
        dsu.par[v] = parV;
        st.pop();
    }
}

void process(const int &tc)
{
    dsu = DisjointsSet(n);
    int cnt = 0;
    for(int i = q; i >= 1; i--)
    {
        int t = queries[i].t;
        int u = queries[i].u;
        int v = queries[i].v;
        if(t == 2)
        {
            if(pos.count(mp(u, v)) == 0) pos[mp(u, v)] = ++cnt;
            int id = pos[mp(u, v)];
            st[id].push(i);
            lef[i] = q + 1;
        }
        if(t == 1)
        {
            if(pos.count(mp(u, v)) == 0) pos[mp(u, v)] = ++cnt;
            int id = pos[mp(u, v)];
            if(st[id].empty()) rig[i] = q + 1;
            else
            {
                rig[i] = st[id].top();
                lef[st[id].top()] = i;
                st[id].pop();
            }
        }
    }
    solve(1, q);
    for(int i = 1; i <= q; i++) if(queries[i].t == 3) cout << ans[i];
}
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
