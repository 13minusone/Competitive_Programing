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

const int N = 3e5 + 5;
const ll mod = 998244353;
//const ll base = 311;
//const int bl = 488;
const int Log = 19;
int n, hi[N], par[N][25], c[N], lca[N], k, ok[N];
bool t = true;
ll dp[N][2], pre[N], suf[N];
vector<int>edge[N], col[N];
void dfs(int u, int pre)
{
    FOR(i,1,Log)par[u][i] = par[ par[u][i-1]][i-1];
    for(int v : edge[u]) if(v != pre)
    {
        hi[v] = hi[u] + 1;
        par[v][0] = u;
        dfs(v,u);
    }
}
int getlca(int u, int v)
{
    if(hi[u] < hi[v])swap(u,v);
    FD(i,Log,0)
    {
        if(hi[par[u][i]] >= hi[v]) u = par[u][i];
    }
    if(u == v)return u;
    FD(i,Log, 0)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
bool cmp(int a, int b)
{
    return ok[a] < ok[b];
}
void solve(int u, int pref)
{
    if(!t)return;
    if(c[u] != 0)
    {
        int v = u;
        while(v != lca[c[u]])
        {
            v = par[v][0];
            if(c[v] == 0)c[v] = c[u];
            else if(c[v] != c[u]){
                    t = false;
                    return;
            }
            else break;
        }
        ok[u] = 0;
    }
    else ok[u] = 1;
    vector<int>chil;
    for(int v : edge[u]) if(v != pref)
    {
        solve(v, u);
        if(!ok[v])ok[u] = 0, chil.pb(v);
    }
    if(ok[u])return;
    if(c[u] == 0)
    {
        //cout << 1 << endl;
        int Sz = SZ(chil);
        suf[Sz] = 1;
        if(chil[0] != pref&& !ok[chil[0]])pre[0] = (dp[chil[0]][1] + dp[chil[0]][0])%mod;
        else pre[0] = 1;
        REP(i,1,Sz)pre[i] = (1LL * pre[i-1] * (dp[chil[i]][1] + dp[chil[i]][0]) )%mod;
        FD(i,Sz-1,0)suf[i] = (1LL * suf[i+1] * (dp[chil[i]][1] + dp[chil[i]][0]) )%mod;
        ll s = (1LL*dp[chil[0]][1] * suf[1])%mod;
        REP(i,1,Sz)
        {
            s += (((1LL*dp[chil[i]][1] * pre[i-1])%mod) * suf[i+1])%mod;
        }
        //cout << u << " " << s << endl;
        dp[u][1] = s;
        dp[u][0] = pre[Sz-1];
    }
    else{
        dp[u][0] = 0;
        dp[u][1] = 1;
        for(int v : chil)
        {
            if(c[v] == c[u])dp[u][1] *= dp[v][1];
            else dp[u][1] *= (dp[v][0] + dp[v][1]) %mod;
            dp[u][1] %= mod;
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
    cin >> n >> k;
    FOR(i,1,n){
        cin >> c[i];
        col[c[i]].pb(i);
    }
    REP(i, 1, n)
    {
        register int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    par[1][0]=1;
    dfs(1,-1);
    //cout << getlca(8,9) << endl;
    FOR(i,1,k)
    {
        lca[i] = col[i][0];
        for(int v : col[i])lca[i] = getlca(lca[i], v);
        //cout << i << " " << lca[i] << endl;
        if(c[lca[i]] == 0)c[lca[i]] = i;
        else if(c[lca[i]] != i)t = false;
    }
    solve(1,-1);
    if(t)cout << (dp[1][1])%mod;
    else cout << 0 << endl;
}

