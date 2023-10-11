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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, sz[N], par[N][21], LOG = 20, hi[N], m;
vector<int>edge[N];
void dfs(int u, int pre)
{
    sz[u] = 1;
    FOR(i,1,LOG)
        par[u][i] = par[ par[u][i - 1] ][i - 1];
    for(int &v : edge[u])if(v != pre)
    {
        hi[v] = hi[u] + 1;
        par[v][0] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int getLca(int u, int v)
{
    if(hi[u] < hi[v])swap(u, v);
    FD(i,LOG,0)
        if(hi[par[u][i]] >= hi[v])
            u = par[u][i];
    if(u == v)return u;
    FD(i,LOG, 0)
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
int dist(int u, int v, int lca)
{
    return hi[u] + hi[v] - 2 * hi[lca];
}
void init(void)
{
    cin >> n;
    REP(i,1,n)
    {
        register int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
}
void process(void)
{
    dfs(1,-1);
    cin >> m;
//    cout << dist(2,3,getLca(2,3));
    while(m--)
    {
        register int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int AB = dist(a,b,getLca(a,b));
        int XY = dist(a,x,getLca(a,x)) + dist(b,y,getLca(y,b)) + 1;
        int YX = dist(a,y,getLca(a,y)) + dist(b,x,getLca(x,b)) + 1;
       //cout << AB << " " << XY << " " << YX << endl;
        minimize(XY,k + 1);
        minimize(YX,k + 1);
        minimize(AB,k + 1);
        //cout << AB << " " << XY << " " << YX << endl;
        if(((k - AB) * (k - XY) * (k - YX)) % 2 == 0)cout << "YES";
        else cout << "NO";
        cout << endl;
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

