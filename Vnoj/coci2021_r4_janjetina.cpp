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

const int N = 1e5+ 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, k, sz[N], cnt[N], maxx = 0,BIT[N + 20];
ll ans = 0;
vector<ii>edge[N];
bool vis[N];
void updA(int x, int val)
{
    if(x == 0)return;
    for(;x <= maxx; x += (x &(-x)))
        BIT[x] += val;
    return;
}
void updD(int x)
{
    if(x == 0)return;
    for(;x <= maxx; x += (x &(-x)))
        BIT[x] = 0;
    return;
}
int getVal(int x)
{
    if(x == 0)return 0;
    int ans = 0;
    for(;x > 0; x-= (x & (-x)))
        ans += BIT[x];
    return ans;
}
vector<ii>val;
void dfs(int u, int pre, int Maxw, int depth = 1)
{
    maximize(maxx, depth);
    val.pb(ii(Maxw, depth));
    //cout << u << " " << pre <<" "<<  depth << " " << getVal(k2 - depth) - getVal(max(0,k1 -depth - 1)) << endl;
    for(ii &v : edge[u])if(v.fi != pre && !vis[v.fi])
        dfs(v.fi, u, max(Maxw, v.se), depth + 1);
}
int getSZ(int u, int pre)
{
    if(vis[u])return 0;
    sz[u] = 1;
    for(ii &v : edge[u])if(v.fi != pre && !vis[v.fi])
    {
        sz[u] += getSZ(v.fi, u);
    }
    return sz[u];
}
int getCentroid(int u, int Sizetree, int p)
{
    for(ii &v : edge[u])
        if(v.fi != p && !vis[v.fi] && sz[v.fi] * 2 > Sizetree)
            return getCentroid(v.fi,Sizetree, u);
    return u;
}
void CreateCentroid(int u, int pre)
{
    u = getCentroid(u, getSZ(u, -1), -1);
    vis[u] = 1;
    //cout << u << " " << pre << endl;
    maxx = 0;
    for(ii &v : edge[u])if(v.fi != pre && !vis[v.fi])
        dfs(v.fi, u, v.se);
    sort(all(val));
    for(ii &i : val)
    {

        if(i.fi >= i.se){
            ans++;
            ans += getVal(min(maxx,i.fi - i.se));
        }
        updA(i.se, 1);
        //cout << i.fi << " " << i.se << " " << ans << endl;
    }
    //cout << ans << endl;
    val.clear();
    FOR(i,1,maxx)
        updD(i);
    maxx = 0;
    for(ii &v : edge[u])if(v.fi != pre && !vis[v.fi]){
        dfs(v.fi, u, v.se);
        sort(all(val));
        for(ii &i : val)
        {
            if(i.fi >= i.se){
                ans -= getVal(min(maxx, i.fi - i.se));
                //ans++;
            }
            updA(i.se, 1);
        }

        FOR(i,1,maxx)
            updD(i);
        val.clear();
        maxx = 0;
    }
//    cout << endl;
//    FOR(i,0,5)
//        cout << BIT[i] <<" " ;
//    cout << endl;
    //cout << ans << endl;
    for(ii &v : edge[u])if(v.fi != pre && !vis[v.fi])
        CreateCentroid(v.fi, u);
}
void init(void)
{
    cin >> n >> k;
    memset(vis,0, n + 1);
    memset(BIT,0, n + 20);
    FOR(i,1,n-1)
    {
        register int u, v, w;
        cin >> u >> v >> w;
        w -= k;
        edge[u].pb(ii(v,w));
        edge[v].pb(ii(u,w));
    }
}
void process(void)
{
    CreateCentroid(1,-1);
    cout << ans * 2LL;
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
