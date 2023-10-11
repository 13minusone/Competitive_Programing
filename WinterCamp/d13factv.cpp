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
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

ll ans = -INF, a[N],dp[N], max_dis = -INF;
ll out[N];
int node_ans = 0, n, c[N], numComp = 0,root[N];
bool d[N], used[N], vis[N];
vector<int>edge[N], vec, gcdEgde[N];
vector<ii>adj;
void pre()
{
    FOR(i,2,N-5)
    {
        if(!d[i])
        {
            if(i <= N-5)vec.pb(i);
            for(ll j = 1LL * i * i; j <= N-5;j += i)
                d[j] = 1;
        }
    }
}
void dfs(int u, int pre)
{
    vis[u] = 1;
    ll res = 0;
    for(int v : edge[u])if(v != pre)
    {
        dfs(v,u);
        maximize(res,dp[v]);
    }
    dp[u] = res +  a[u];
//    cout << u <<  "  " << dp[u] << endl;
}
void solve(int u, int pre)
{
    ii res = ii(-INF,-INF);
    ii node = ii(0,0);
    ll dist = -INF;
    for(int v : edge[u])if(v != pre)
    {
        out[v] = -INF;
        if(dp[v] >= res.fi){
            dist = res.se;
            res.se = res.fi;
            node.se = node.fi;
            node.fi = v;
            maximize(res.fi, dp[v]);
        }
        else if(res.se < dp[v])dist = res.se, res.se = dp[v],node.se = v;
        else maximize(dist,dp[v]);
    }
   // cout << u << " " << out[u] << endl;
    if(maximize(max_dis,max({2LL * (res.fi + out[u]) + 3LL * a[u], 2LL * (res.fi + res.se + out[u]) + 3LL * a[u], 2ll * (res.fi + res.se + dist) +3LL *  a[u]})))
        node_ans = u;

    for(int v : edge[u])if(v != pre)
    {
        maximize(out[v], max(a[u],a[u] + out[u]));
         if(v != node.fi)
            maximize(out[v], res.fi + a[u]);
        else
            maximize(out[v], res.se + a[u]);
        solve(v,u);
    }
}
ll calc(int val)
{
    set<int>usedNode;
    max_dis = -INF;
    node_ans = 0, numComp = 0;
   for(int i = val; i <= N-5;  i += val)
   {
       for(int &j : gcdEgde[i])
       {
           int x  = adj[j].fi;
           int y  = adj[j].se;
           edge[y].pb(x);
           edge[x].pb(y);
           //cout << x << " " << y << endl;
           usedNode.insert(x);
           usedNode.insert(y);

       }
   }
    for(int i : usedNode)
    {
        //dp[i] = 0;
        out[i] = -INF;
        if(!vis[i])
        {
            numComp++;
            root[numComp] = i;
            dfs(i,i);
        }
    }
    FOR(i,1,numComp){
        out[root[i]] = -INF;
        solve(root[i],root[i]);
    }
    for(int i : usedNode){
        edge[i].clear();
        out[i] = -INF;
        vis[i] = 0;
        dp[i] = 0;
    }
   //cout << root << " " << max_dis << " " << node_ans << endl;
   if(node_ans == 0 || numComp == 0)return -INF;
    return max_dis;
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
    pre();
    while(t--)
    {
        cin >> n;
        ans = -INF;
        FOR(i,1,n)
            cin >> a[i];
        FOR(i,1,n)
            cin >> c[i];
        FOR(i,0,n-2)
        {
            register int x, y;
            cin >> x >> y;
            adj.pb(ii(x,y));
            gcdEgde[__gcd(c[x],c[y])].pb(i);
        }
        for(int i : vec)
            maximize(ans, calc(i));
        if(ans <= -INF)cout << "No Solution" << endl;
        else cout << ans << endl;
    }

}
