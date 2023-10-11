// Onegai no bug
// Author : 13minusone
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

const int N = 1e4 + 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
const int LOG = 15;
int n, code[N];
ll dp[N][LOG+1];
vector<int>edge[N];
void dfs(int u, int pre)
{
    FOR(i,1,LOG)dp[u][i] = i;
    for(int v : edge[u])if(v != pre)
    {
        dfs(v,u);
        FOR(i,1,LOG)
        {
            ll ans = mod;
            FOR(j,1,LOG)if(i != j)minimize(ans,dp[v][j]);
            dp[u][i] += ans;
        }
    }
}
void trace(int u, int pre,int node)
{
    code[u] = node;
    for(int v : edge[u])if(v != pre)
    {
        int t = 0;
           FOR(j,1,LOG)
           if(node != j &&(t ==0 ||  dp[v][j] < dp[v][t])) t = j;
        trace(v,u,t);

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
    cin >> n;
    REP(i,1,n)
    {
        register int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    dfs(1,-1);
    ii ans = ii(mod,0);
    FOR(i,1,LOG)minimize(ans,ii(dp[1][i],i));
    cout << ans.fi << endl;
    trace(1,-1,ans.se);
    FOR(i,1,n)cout << code[i] << endl;
}
