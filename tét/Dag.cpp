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

const int N = 2e5 + 5;
const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e18 + 7;
int n, m, c[N], Node[N], nTopo = 0, id[N];
bool vis[N];
ll d[N],f[N], sum = 0;
ii edge[N];
vector<ii>adj[N];
vector<int> Dag[N];
void init(void)
{
    cin >> n >> m;
    FOR(i,1,m){
        register int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(ii(v,w));
        adj[v].pb(ii(u,w));
        edge[i] = ii(u, v);
        c[i] = w;
        sum += w;
    }
}
void dfs(int u) {
    vis[u] = true;
    for (auto i : Dag[u])
        if (!vis[i]) dfs(i);
    id[++nTopo] = u;
}
void add(ll &a, const ll b)
{
    a += b;
    while(a >= MOD) a -= MOD;
}
void process(void)
{
    priority_queue<pair<ll, int>>qu;
    FOR(i,1,n)
        d[i] = INF;
    d[1] = 0;
    qu.push({d[1], 1});
    while(!qu.empty())
    {
        pair<ll, int>  x = qu.top();
        qu.pop();
        if(d[x.se] != -x.fi)continue;
        for(ii v : adj[x.se])
            if(minimize(d[v.fi], d[x.se] + v.se))
                qu.push({-d[v.fi], v.fi});
    }
    FOR(j,1,m)
    {
            ii i = edge[j];
            if(d[i.fi] + c[j] == d[i.se]){
                Dag[i.fi].pb(i.se);
            }
            if(d[i.se] + c[j] == d[i.fi]){
                Dag[i.se].pb(i.fi);
            }
    }
    memset(vis,0,sizeof vis);
    FOR(i,1,n)
        if(!vis[i])
            dfs(i);
    reverse(id + 1, id + nTopo + 1);
    f[1] = 1;
    for (int i = 1; i <= nTopo; ++i){
        for (int j : Dag[id[i]]) add(f[j], f[id[i]]);
    }
    FOR(i,1,n)
        if(d[i] != INF)
            cout << d[i] << " " << f[i] << endl;
        else
            cout << -1 << " " << 0 << endl;
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


