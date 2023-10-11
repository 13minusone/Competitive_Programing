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

const int N = 1e5 + 5;
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;
const int Log = 22;
int u, par[N][23], cnt = 0, hi[N], sta[N], fin[N], a[N], n, d[N], q, st[4 *N], lz[4*N];
ll  dp[N][305];
vector<int>edge[N];
ii h[N];
void down(int id)
{
    int &t = lz[id];
    st[id << 1|1] += t;
    lz[id << 1|1] += t;
    st[id << 1] += t;
    lz[id << 1] += t;
    t = 0;
}
void upd(int u, int v, int val, int id = 1, int l = 1, int r = n+1)
{
    if(l > v || r < u || l > r)return ;
    if(l >= u && r <= v)
    {
        lz[id]+=val;
        st[id]+= val;
        return;
    }
    down(id);
    int mid = (l+r) >> 1;
    upd(u, v, val, id << 1, l, mid);
    upd(u, v, val, id << 1|1, mid + 1, r);
    st[id] = st[id << 1 ] + st[id << 1|1];
}
int get(int pos, int id = 1, int l = 1, int r = n+1)
{
    if(l > pos || r < pos || l > r)return 0;
    if(l == r)return st[id];
    int mid = (l+r) >> 1;
    down(id);
    if(pos <= mid)return get(pos, id << 1, l, mid);
    else return get(pos, id << 1|1, mid+1, r);
}
void dfs(int u, int pre)
{
    sta[u] = ++cnt;
    FOR(i,1,Log)par[u][i] = par[ par[u][i-1]][i-1];
    for(int v : edge[u]) if(v != pre)
    {
        hi[v] = hi[u] + 1;
        par[v][0] = u;
        dfs(v,u);
    }
    fin[u] = cnt;
}
int lca(int u, int v)
{
    if(hi[u] < hi[v]) swap(u, v);
    if(sta[u] <= fin[v] && sta[u] >= sta[v])return v;
    FD(i, Log, 0)
    {
        if(hi[par[u][i]] >= hi[v])u= par[u][i];
    }
    if(u == v)return u;
    FD(i, Log, 0)
    {
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int solve(int id)
{
    int k, m, root;
    cin >> k >> m >> root;
    FOR(i,1,k){
        cin >> a[i];
        upd(sta[a[i]], fin[a[i]],1);
        d[a[i]] = id;
    }
    int res = get(sta[root]);
    FOR(i,1,k){
        int dpo = get(sta[a[i]]);
        int ilca = lca(a[i],root), opt = get(sta[ilca]);
        dpo =  dpo + res - 2*opt + (d[ilca] == id) - 1;
        h[i] = ii(dpo,a[i]);
       //cout << dpo << " " << (d[ilca] == id) << " " ;
    }
    //cout << endl;
    sort(h+1, h + 1 + k);
    dp[0][0] = 1;
    FOR(i,1,k)
    {
        FOR(j,1,min(i,m))
        {
            dp[i][j] = ((1LL*dp[i-1][j] * max(0,j - h[i].fi))%mod + dp[i-1][j-1])%mod;
            //cout << dp[i][j] <<" " ;
        }
        //cout << endl;
    }
    //cout << endl;
    ll ans = 0;
    FOR(i,1,m)
    {
        //cout << dp[k][i] << endl;
        ans += dp[k][i];
        ans%=mod;
    }
    FOR(i,1,k)upd(sta[a[i]], fin[a[i]],-1);
    return ans;
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
    cin >> n >> q ;
    FOR(i,1,n-1)
    {
        register int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    dfs(1,-1);
    while(q)
    {
        cout << solve(q) <<endl;
        q--;
    }
}
