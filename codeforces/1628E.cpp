// Author : Nyanpasuuuuu
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 6e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
struct Data{
    int l, r, w;
    bool operator <(const Data &other)const
    {
        return w < other.w;
    }
};
vector<Data>edge;
vector<int>adj[N];
int n, m, par[N], C[N], up[N][21], LOG = 19, hi[N], All[4 * N], st[4 * N], lz[4 * N], q, in[N], out[N], cnt = 0;
int root(int u){
    return (par[u] == u ? u : par[u] = root(par[u]));
}
bool check(int u, int v)
{
    return(in[u] <= in[v] && in[v] <= out[u]);
}
void dfs(int u)
{
    FOR(i, 1, LOG)up[u][i] = up[ up[u][ i - 1]][i - 1];
    in[u] = ++cnt;
    for(int v : adj[u]){
        hi[v] = hi[u] + 1;
        up[v][0] = u;
        dfs(v);
    }
    out[u] = cnt;
}
int Lca(int u, int v)
{
    if(!u)return v;
    if(!v)return u;
    if(check(u,v))return u;
    if(check(v,u))return v;
    FD(i,LOG,0)
        if(up[u][i] && !check(up[u][i], v)){
            u = up[u][i];
        }
    return up[u][0];
}
void build(int id = 1, int l = 1, int r = n)
{
    if(l == r){
        All[id] = l;
        lz[id] = -1;
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    All[id] = Lca(All[id << 1], All[id << 1|1]);
    lz[id] = -1;
}
void Down(int id)
{
    if(lz[id] == 1)st[id] = All[id];
    else st[id] = 0;
    if(id << 1|1 <= 4 * n)lz[id << 1] = lz[id << 1|1] = lz[id];
    lz[id] = -1;
    return;
}
void upd(int u, int v,bool val, int id = 1, int l = 1, int r = n)
{
    if(lz[id] != -1)Down(id);
    if(l > v || r < u)return;
    if(l >= u && r <= v){
        lz[id] = val;
        Down(id);
        return;
    }
    int mid = (l+r) >> 1;
    upd(u, v, val, id << 1, l, mid);
    upd(u, v, val, id << 1|1, mid + 1, r);
    st[id] = Lca(st[id << 1], st[id << 1|1]);
   // cout << l <<" " << r << " " << st[id << 1|1] << endl;
}
void init(void)
{
    cin >> n >> q;
    REP(i,1,n){
        par[i] = i;
        C[i] = 0;
        register int x, y, w;
        cin >> x >> y >> w;
       edge.push_back({x, y, w});
    }
}
void process(void)
{
    par[n] = n;
    C[n] = 0;
    sort(all(edge));
    memset(st,0,sizeof st);
    for(auto[u,v,w] : edge)
    {
        u = root(u);
        v = root(v);
        n++;
        par[n] = par[u] = par[v] = n;
        adj[n].pb(u);
        adj[n].pb(v);
        C[n] = w;
    }
    dfs(n);
   build();
    while(q--)
    {
        register int type;
        cin >> type;
        if(type == 3){
            register int u;
            cin >> u;
            int x = Lca(st[1], u);
            //cout << st[1] << endl;
            if(C[x] > 0)cout << C[x] << endl;
            else cout << -1 << endl;
        }
        else{
            register int x, y;
            cin >> x >> y;
            upd(x, y, 2 - type);
        }
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
        init();
        process();
    }

}
