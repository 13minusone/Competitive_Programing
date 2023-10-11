// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "meeting"
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

const int N = 1e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e15 + 7;
int n, q, LOG = 19, par[N][21], hi[N], Dist[1005][1005];
ll preSum[N], pre[N], suf[N];
vector<int>edge[N];
void init(void)
{
    cin >> n >> q;
    REP(i,1,n){
        register int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
}
void dfs(int u, int pre)
{
    FOR(i,1,LOG)par[u][i] = par[par[u][i - 1]][i - 1];
    for(int v : edge[u])if(v != pre)
    {
        par[v][0] = u;
        hi[v] = hi[u] + 1;
        dfs(v, u);
    }
}
int getLCA(int u, int v)
{
    if(hi[u] < hi[v])swap(u, v);
    FD(i, LOG, 0)
        if(hi[par[u][i]] >= hi[v])
            u = par[u][i];
    if(u == v)return u;
    FD(i,LOG,0)
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
vector<int> TracePath(int i, int j)
{
    vector<int> Di(n + 1, -1);
    vector<int> trace(n + 1, -1);
    queue<int> qu;
    qu.push(i);
    Di[i] = 0;
    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for(int v : edge[x]) if(Di[v] == -1)
        {
            Di[v] = Di[x] + 1;
            trace[v] = x;
            qu.push(v);
        }
    }
    vector<int>vec;
    vec.pb(j);
    while(trace[j] != -1)
    {
        j = trace[j];
        vec.pb(j);
    }
    reverse(all(vec));
    return vec;
}
void process(void)
{
    FOR(i,1,n)
        preSum[i] = preSum[i - 1] + i;
    dfs(1, -1);
    if(n <= 1000){
    FOR(i,1,n)
    {
        FOR(j,1,n)
            Dist[i][j] = 0;
        queue<int>qu;
        qu.push(i);
        while(!qu.empty())
        {
            int x = qu.front();
            qu.pop();
            for(int v : edge[x])if(v != i && Dist[i][v] == 0){
                Dist[i][v] = Dist[i][x] + 1;
                qu.push(v);
            }
        }
    }}
    FOR(o,1,q)
    {
        register int u, i, j, a, b;
        cin >> u >> i >> j >> a >> b;
        if(n <= 1000){
            vector<int> vec = TracePath(i, j);
            pre[0] = 0, suf[SZ(vec) - 1] = 0;
            FOR(x,1,SZ(vec) - 1)
            {
                int C = (Dist[u][vec[x-1]] > Dist[u][vec[x]] ? a : b);
                pre[x] = pre[x-1] + 1LL * C * x;
            }
            FD(x,SZ(vec) - 2, 0)
            {
                int C = (Dist[u][vec[x + 1]] > Dist[u][vec[x]] ? a : b);
                suf[x] = suf[x + 1] + 1LL * C * (SZ(vec) - 1 - x);
            }
            ll ans = INF;
            FOR(x, 0, SZ(vec) - 1){
                minimize(ans, pre[x] + suf[x]);
                //cout << x << " " << ans << endl;
            }
            cout << ans << endl;
        }
        else if(b >= 1LL * n * a)
        {
            ll ans = 0;
            int x, y, v, node, dist1, dist2;
            x = getLCA(u,i);
            y = getLCA(u,j);
            v = getLCA(i,j);
            node = x;
            if(hi[node] < hi[y])node = y;
            if(hi[v] > hi[node])node = v;
            if(node == x){
                dist1 = hi[i] - hi[node];
                dist2 = hi[j] - hi[v] + hi[x] - hi[v];
                ans = (1LL * a * (preSum[dist1] + preSum[dist2]));
            }
            else if(node == y)
            {
                dist2 = hi[j] - hi[node];
                dist1 = hi[i] - hi[v] + hi[y] - hi[v];
                ans = (1LL * a * (preSum[dist1] + preSum[dist2]));
            }
            else{
                dist1 = hi[j] - hi[node];
                dist2 = hi[i] - hi[node];
                ans = (1LL * a * (preSum[dist1] + preSum[dist2]));
            }
            cout << ans << endl;
        }
    }
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


