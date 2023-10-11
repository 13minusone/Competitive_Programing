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

const int N = 5e2 + 5;
//const int MOD =1e9+7;
// 998244353
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e18 + 7;
int n, m, c[10005], Node[N], nTopo = 0, id[N], deg[N], par[N];
bool vis[N];
ll d[N][N], cnt[N][N][2], ans[10005];
ii edge[10005];
int MOD[2] = {998244353, 1000000007};
vector<ii>adj[N];
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
}
void add(ll &a, const ll b, int mod)
{
    a += b;
    while(a >= mod) a -= mod;
}
vector<int>candidate;
void dfs(int v, int p, ll d[N]) {
    for (auto i : adj[v])
        if (i.fi != p &&
        d[i.fi] == d[v] + c[i.se]) {
            candidate.emplace_back(i.se);
            dfs(i.fi, v, d);
    }
}
void Dijkstra(int u, ll d[N])
{
    d[u] = 0;
    cnt[u][u][0] = cnt[u][u][1] = 1;
    priority_queue<ii>qu;
    qu.push({d[u], u});
    while(!qu.empty())
    {
        pair<ll, int>  x = qu.top();
        qu.pop();
        if(d[x.se] != -x.fi)continue;
        for(ii v : adj[x.se])
            if(d[v.fi] > d[x.se] + c[v.se]){
                d[v.fi] = d[x.se] + c[v.se];
                cnt[u][v.fi][1] = cnt[u][x.se][1];
                cnt[u][v.fi][0] = cnt[u][x.se][0];
                qu.push({-d[v.fi], v.fi});
            }
            else if(d[v.fi] == d[v.se] + c[v.se]){
                add(cnt[u][v.fi][1], cnt[u][x.se][1], MOD[1]);
                add(cnt[u][v.fi][0], cnt[u][x.se][0], MOD[0]);
            }
    }
}
void process(void)
{
    memset(d,0x3f,sizeof d);
    FOR(i,1,n)Dijkstra(i,d[i]);
    FOR(i,1,n)
    {
        candidate.clear();
        dfs(i,-1,d[i]);
        for(int j : candidate)
        {
            int v = (d[i][edge[j].fi] > d[i][edge[j].se] ? edge[j].fi : edge[j].se);
            int u = edge[j].fi + edge[j].se - v;
            FOR(t,1,n)
                if(d[i][u] + c[j] + d[v][t] == d[i][t]
                   && 1LL * cnt[i][u][0] * cnt[v][t][0] % MOD[0] == cnt[i][t][0]
                   && 1LL * cnt[i][u][1] * cnt[v][t][1] % MOD[1] == cnt[i][t][1])
                ans[j]++;
        }
    }
    FOR(i,1,m)
        cout << ans[i]/ 2 << endl;
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


