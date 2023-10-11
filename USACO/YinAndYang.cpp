// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "yinyang"
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
//const int INF = 1e9 + 7;
int n, pre[N * 2], cnt[2 * N][2], have[2 * N], sz[N];
ll ans = 0;
vector<ii>edge[N];
bool vis[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n - 1){
        register int x, y, w;
        cin >> x >> y >> w;
        if(!w)w = -1;
        edge[x].pb(ii(y,w));
        edge[y].pb(ii(x,w));
    }
}
int getSize(int u, int pre)
{
    sz[u] = 1;
    for(auto [v, w] : edge[u])if(v != pre && !vis[v]){
        getSize(v,u);
        sz[u] += sz[v];
    }
    return sz[u];
}
int getCentroid(int u, int Total, int pre)
{
    for(auto [v, w] : edge[u])
        if(v != pre && !vis[v] && sz[v] * 2 > Total)
           return getCentroid(v, Total, u);
    return u;
}
vector<ii>vec;
void dfs(int u, int par, int sum)
{
    if(vis[u])return;
    if(pre[sum + n])vec.pb(ii(sum, 1));
    else vec.pb(ii(sum, 0));
    if(sum == 0 && pre[sum + n] > 1)ans++;
    pre[sum + n]++;
    for(auto [v, w] : edge[u])if(v != par && !vis[v])
        dfs(v, u, sum + w);
    pre[sum + n]--;
}
vector<int>NeedErase;
void solve(int u)
{
    int Centroid = getCentroid(u,getSize(u, - 1), -1);
    vis[Centroid] = 1;
    pre[n] = 1;
    NeedErase.clear();
    for(auto [v, w] : edge[Centroid])
    {
        vec.clear();
        dfs(v, Centroid, w);
        for(ii x : vec)
        {
            ans += cnt[- x.fi + n][1];
            if(x.se)ans += cnt[-x.fi + n][0];
        }
        for(ii x : vec)
        {
            cnt[x.fi + n][x.se]++;
            if(!have[x.fi + n])NeedErase.pb(x.fi + n);
            have[x.fi + n] = 1;
        }
    }
    for(int i : NeedErase)cnt[i][1] = cnt[i][0] = have[i] = 0;
    for(ii v : edge[Centroid])
        if(!vis[v.fi])
            solve(v.fi);
    //cout << Centroid << " " << ans << endl;
}
void process(void)
{
    solve(1);
    cout << ans << endl;
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


