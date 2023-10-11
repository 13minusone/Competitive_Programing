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

const int N = 3e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, q, par[N], extra, maxx[N][22], hi[N], up[N][22], LOG = 19, p[N][22];
vector<int>edge[N];
int root(int u){
    return (par[u] < 0 ?u :  par[u] = root(par[u]));
}
void join(int u, int v)
{
    if((u = root(u)) == (v = root(v))){
        par[extra] = INF;
        extra++;
        return;
    }
    par[extra] += (par[u] + par[v]);
    par[u] = extra;
    par[v] = extra;
    edge[extra].pb(u);
    edge[extra].pb(v);
    extra++;
    return;
}
void dfs(int u)
{
    FOR(i,1,LOG)
    {
        up[u][i] = up[up[u][i - 1]][i-1];
        maxx[u][i] = max(maxx[up[u][i - 1]][i - 1], maxx[u][i - 1]);
    }
    for(int v : edge[u]){
        //cout << u << " " << v << endl;
        hi[v] = hi[u] + 1;
        up[v][0] = u;
        maxx[v][0] = max(0,u - n);
        dfs(v);
    }
}
int getLCA(int u, int v)
{
    if(hi[u] < hi[v])swap(u, v);
    int res = 0;
    FD(i,LOG,0)
        if(hi[up[u][i]] >= hi[v]){
            maximize(res, maxx[u][i]);
            u = up[u][i];
        }
    if(u == v)return res;
    FD(i,LOG,0)if(up[u][i] != up[v][i])
    {
        maximize(res, maxx[u][i]);
        maximize(res, maxx[v][i]);
        u = up[u][i];
        v = up[v][i];
    }
    maximize(res, maxx[u][0]);
    maximize(res, maxx[v][0]);
    return res;
}
void init(void)
{
    cin >> n >> m >> q;
    extra = n + 1;
    FOR(i,1,n + m){
        par[i] = -1;
        hi[i] = 0;
        edge[i].clear();
        FOR(j,0,LOG)up[i][j] = 0, maxx[i][j] = p[i][j] = 0;
    }
    FOR(i,1,m)
    {
        register int u, v;
        cin >> u >> v;
        join(u, v);
        //cout << extra << endl;
    }
}
int getMax(int l, int r)
{
    if(l > r)return 0;
    int k = log2(r - l + 1);
    //cout << l << " " << r << " " << k << endl;
    return max(p[l][k], p[r - (1 << k) + 1][k]);
}
void process(void)
{
    FOR(i,1,extra)if(par[i] != INF && root(i) == i){
        dfs(i);
        break;
    }
    FOR(i,1,n - 1){
        p[i][0] = getLCA(i,i+1);
        //cout << p[i][0] << " ";
    }
    //cout << endl;
    FOR(j,1,LOG)
        FOR(i,1,n - (1 << j) + 1)
            p[i][j] = max(p[i][j - 1], p[i + (1 << (j - 1))][j - 1]);
    //cout << getMax(1,3) << endl;
    while(q--)
    {
        register int l, r;
        cin >> l >> r;
       cout << getMax(l, r-1) << " ";
    }
    cout << endl;
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
    cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
