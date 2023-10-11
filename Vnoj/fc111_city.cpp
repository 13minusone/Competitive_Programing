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

const int N = 2e5 + 100;
const ll INF =1e14+9;
//const ll base = 311;
//const int block = 488;

int n, m, k, root = 0;
ll dp[64][N];
vector<ii>edge[N];
void solve()
{
    priority_queue<ii>qu;
        //cout << special[i] << endl;
    int ful = (1 << k)-1;
        REP(i,0,(1<<k)){
            FOR(j,0,i >> 1)if((i & j) == j)
            {
                int suf = i ^ j;
                FOR(o,1,n)
                    minimize(dp[o][i], dp[o][j] + dp[o][suf]);
            }
            FOR(j,1,n) if(dp[j][i] != INF) qu.emplace(ii(-dp[j][i], j));
            while(!qu.empty())
            {
                ii res = qu.top();
                qu.pop();
                if(-res.fi != dp[res.se][i])continue;
                for(ii v : edge[res.se]){
                    if(minimize(dp[v.fi][i], -res.fi + v.se))
                        qu.emplace(ii(-dp[v.fi][i], v.fi));
                }
            }
        }
    long ans = *min_element(dp[(1 << k) - 1], d[(1 << k) - 1] + n);
    cout << ans << '\n';
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
    cin >> n >> k >> m;
    int x;
    memset(dp,INF,sizeof dp);
    FOR(i,1,k)
    {
        cin >> x;
        dp[x][1 << (i-1)] = 0;
    }
    int u, v, w;
    FOR(i,1,m)
    {
        cin >> u >> v >> w;
        edge[u].pb(ii(v,w));
        edge[v].pb(ii(u,w));
    }
    solve();
    cout << ans;
}
