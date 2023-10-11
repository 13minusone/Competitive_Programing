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

const int N = 3e3 + 5;
const int MOD =1e9+7;
// 998244353
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e15 + 7;
int n, m, c[10005], Node[N], nTopo = 0, id[N], deg[N], par[N], S, T, Deg[N];
bool vis[N];
ll d[N][N], cnt[N][N], f[N];
ii edge[10005];
vector<ii>adj[N];
vector<int>Newedge[N];
void init(void)
{
    cin >> n >> m;
    FOR(i,1,m){
        register int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(ii(v,i));
        adj[v].pb(ii(u,i));
        c[i] = w;
        edge[i] = ii(u,v);
    }
    cin >> S >> T;
}
void add(ll &a, const ll &b)
{
    a += b;
    while(a >= MOD) a -= MOD;
}
void Dijkstra(int u, ll d[N])
{
    FOR(i,1,n)
        d[i] = INF;
    d[u] = 0;
    cnt[u][u] = 1;
    priority_queue<pair<ll, int>>qu;
    qu.push({d[u], u});
    while(!qu.empty())
    {
        pair<ll, int>  x = qu.top();
        qu.pop();
        if(d[x.se] != -x.fi)continue;
        if(!Have[u])
        for(ii v : adj[x.se])
            if(d[v.fi] > d[x.se] + c[v.se]){
                d[v.fi] = d[x.se] + c[v.se];
                cnt[u][v.fi] = cnt[u][x.se];
                qu.push({-d[v.fi], v.fi});
            }
            else if(d[v.fi] == d[x.se] + c[v.se]){
                //cout << v.fi << " " << x.se << endl;
                add(cnt[u][v.fi], cnt[u][x.se]);
            }
    }
}
void dfs(int u)
{
    vis[u] = 1;
    for(int v : Newedge[u])
        if(!vis[v])
            dfs(v);
    id[++nTopo] = u;
}
void check(int u)
{
    vis[u] = 1;
    for(int v : Newedge[u])
        if(!vis[v])
            check(v);
}
void process(void)
{
    memset(vis,0,sizeof vis);
    FOR(i,1,n)
    {
        memset(vis,0,sizeof vis);
        check(i);
        FOR(j,1,n)
            if(!vis[j])Have[i][j] = 0;
            else Have[i][j] = 1;
    }
    FOR(i,1,n)
        Dijkstra(i, d[i]);
    FOR(i,1,m)
    {
        ii j = edge[i];
        if(d[S][j.fi] != INF && d[S][j.se] != INF)
        {
            if(d[S][j.fi] + c[i] == d[S][j.se]){
                Newedge[j.fi].pb(j.se);
            }
            if(d[S][j.se] + c[i] == d[S][j.fi]){
                Newedge[j.se].pb(j.fi);
            }
        }
    }
    f[S] = 0;
    memset(vis,0,sizeof vis);
    FOR(i,1,n)
        if(!vis[i])dfs(i);

    reverse(id + 1, id+ nTopo + 1);
    FOR(o,1,nTopo){
        int i = id[o];
        f[i] = 1LL * cnt[S][i] * (cnt[S][i] - 1) % MOD;
        if(i == S){
            f[i] = 0;
            continue;
        }
        FOR(j,1,o - 1){
            int t = id[j];
            f[i] = (f[i] - (1LL * (1LL * f[t] * cnt[t][i] % MOD) * cnt[t][i] % MOD) +MOD) % MOD;
        }
       // cout << i << " " << f[i] << endl;
    }
    cout << f[T] << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    cerr << "TIME : " << TIME << "s\n";
}


