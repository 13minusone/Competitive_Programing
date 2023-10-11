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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e5 + 5;
const ll MOD =1e9 + 9;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e18;
int n, m, k;
vector<int>adj[N];
bool isGood[N], isBeauty[N], vis[N];
void init()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        isGood[x] = 1;
    }
    for(int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        isBeauty[x] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        int sz;
        cin >> sz;
        for(int love = 0; love < sz; love++)
        {
            int x;
            cin >> x;
            adj[i].pb(x);
        }
    }
}
int dp[N][2][2];
void solve(int u, int pre)
{
    dp[u][isGood[u]][isBeauty[u]] = 1;
    int minGood = MOD-9, minBeau = MOD-9, minGB = MOD-9;
    vis[u] = 1;
    for(int i : adj[u])
        if(!vis[i])
        {
            solve(i, u);
            minimize(minGood,dp[i][1][0]);
            minimize(minBeau,dp[i][0][1]);
            minimize(minGB, dp[i][1][1]);
        }
        else{
            minimize(minGood,dp[i][1][0]);
            minimize(minBeau,dp[i][0][1]);
            minimize(minGB, dp[i][1][1]);
        }
    minimize(dp[u][1][0],minGood + 1);
    minimize(dp[u][0][1],minBeau + 1);
    minimize(dp[u][1][1],min(min(minGB, minBeau + minGood) + 1,min(minBeau + dp[u][1][0], minGood + dp[u][0][1])));
   //cout << u << " " << minGB << " " << minBeau << " " << minGood << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        memset(dp,0x3f,sizeof dp);
        solve(1,1);
        if(dp[1][1][1] < N * 10)cout << dp[1][1][1]-1 << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}
