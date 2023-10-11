// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "disrupt"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 5e4 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;

const int INF = 1e9 + 7;
int n, m, cnt = 0, head[N], par[N], sta[N], num[N], hi[N], st[4 * N], sz[N];
vector<int>adj[N];
ii edge[N];
void dfs(int u, int pre)
{
    sz[u] = 1;
    for(int v : adj[u])if(v != pre){
        par[v] = u;
        hi[v] = hi[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void createHLD(int u, int top)
{
    sta[u] = ++cnt;
    num[cnt]  =u;
    head[u] = top;
    int maxx = -1;
    for(int v : adj[u])
        if(v != par[u])
        {
            if(maxx == -1 || sz[v] > sz[maxx])maxx = v;
        }
    if(maxx < 0)return;
    createHLD(maxx, top);
    for(int v : adj[u])
        if(v != par[u] && v != maxx)
            createHLD(v, v);
}
void down(int id)
{
    minimize(st[id << 1], st[id]);
    minimize(st[id << 1|1], st[id]);
}
void upd(int u, int v, int val, int id = 1, int l = 1, int r = n)
{
    if(l > r || u > v || l > v || r < u)return;
    if(l >= u && r <= v){
        minimize(st[id], val);
        return;
    }
    if(st[id] < st[id << 1] || st[id] < st[id << 1|1])down(id);
    int mid = (l+r) >> 1;
    upd(u, v, val, id << 1, l, mid);
    upd(u, v, val, id << 1|1, mid + 1, r);
}
int getVal(int pos, int id = 1, int l = 1, int r = n)
{
    if(l == r)return st[id];
    if(st[id] < st[id << 1] || st[id] < st[id << 1|1])down(id);
    int mid = (l + r) >> 1;
    if(pos <= mid)return getVal(pos, id << 1, l, mid);
    else return getVal(pos, id << 1|1, mid + 1, r);
}
void queryPath(int u, int v, int val)
{
    while(head[u] != head[v])
    {
        if(hi[head[u]] < hi[head[v]])swap(u,v);
        upd(sta[head[u]], sta[u], val);
        u = par[head[u]];
    }
    if(hi[u] > hi[v])swap(u, v);
    upd(sta[u] + 1, sta[v], val);
   // cout << sta[u] + 1 << " " << sta[v] << endl;
}
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n - 1){
        register int x, y;
        cin >> x >> y;
        edge[i] = ii(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
}
void process(void)
{
    fill(st, st + 4 * n + 1, INF);
    dfs(1,-1);
    createHLD(1,1);
    FOR(i,1,m)
    {
        register int x, y, w;
        cin >> x >> y >> w;
        queryPath(x, y, w);
    }
    FOR(i,1,n - 1)
    {
        ii x = edge[i];
        if(x.fi == par[x.se])swap(x.fi, x.se);
       // cout << sta[x.fi] << endl;
        int val = getVal(sta[x.fi]);
        if(val != INF)cout << val << endl;
        else cout << -1 << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".in","r"))
    {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


