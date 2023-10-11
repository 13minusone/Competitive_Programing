// Onegai no bug
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

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
ll ans[N];
int n, sz[N], par[N][21], LOG = 20, hi[N];
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
int Jump(int u, int dist)
{
    FD(i,LOG,0)
    {
        if(dist >= (1 << i)){
            dist -= (1 << i);
            u = par[u][i];
        }
    }
    return u;
}
int getdist(int u, int v, int lca)
{
    return hi[u] + hi[v] - 2 * hi[lca];
}
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        edge[i].clear();
    FOR(i,1,n-1)
    {
        register int x, y;
        cin >> x >> y;
        x++, y++;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}
void process(void)
{
    par[1][0] = 0;
    hi[1] = 0;
    sz[1] = 0;
    dfs(1, -1);
    FOR(i,1,n + 1)
        ans[i] = 0;
    ans[n + 1] = 1;
    for(int &v : edge[1])
        ans[1] += 1LL * sz[v] *(sz[v] - 1)/2;
    ans[2] = (1LL * n *(n - 1)) >> 1;
    ans[2] -= ans[1];
    int Near1 = Jump(2,hi[2] - hi[1] - 1);
    //cout << sz[1] << endl;
    sz[1] = n - sz[Near1];
    ans[2] -= 1LL * sz[2] * sz[1];
    int l = 1, r = 2;
    FOR(i,3,n)
    {
        int Lcal = getLca(i,l);
        int Lcar = getLca(i,r);
        if(getdist(i,l,Lcal) + getdist(i, r, Lcar) == getdist(l,r,1))
            continue;
        if(getdist(i,l,Lcal) + getdist(l,r,1) == getdist(i,r,Lcar))
        {
            ans[i] = 1LL * (sz[l] - sz[i]) * sz[r];
            l = i;
            continue;
        }
        if(getdist(i,r,Lcar) + getdist(l,r,1) == getdist(i,l,Lcal))
        {
            ans[i] = 1LL * (sz[r] - sz[i]) * sz[l];
            r = i;
            continue;
        }
        ans[i] = 1LL * sz[l] * sz[r];
        ans[n + 1] = 0;
        break;
    }
    FOR(i,1,n + 1)
        cout << ans[i] << " \n"[i == n + 1];
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
    cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


