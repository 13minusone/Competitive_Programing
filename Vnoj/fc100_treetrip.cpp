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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

vector<ii>edge[N];
/*
    dp[u][1] = min(sum(min(dp[v][0], dp[v][1]) + b),
                sum(min(dp[v][0], dp[v][1]) + b)(v != a) + dp[a][1] + w(u,a))
    dp[u][0] = min(sum(min(dp[v][0], dp[v][1]) + b)(v != (a,b)) +
                    dp[a][1] + w(a,u) + dp[b][1] + w(b,u));
*/
int n, A, B;
ll dp[N][2];
void dfs(int u, int pre)
{
    ll Best = 0, Best1 = INF, Best2 = INF;
    for(ii v : edge[u])if(v.fi != pre)
    {
        dfs(v.fi,u);
        Best += min(dp[v.fi][0], dp[v.fi][1]) + B;
        ll w =dp[v.fi][1] +1LL * A *  v.se  - (min(dp[v.fi][0], dp[v.fi][1]) + B);
        if(w < Best1)
        {
            Best2 = Best1;
            minimize(Best1, w);
        }
        else minimize(Best2,w);
    }
    dp[u][1] = Best;
    minimize(dp[u][1], Best +  Best1);
    if(SZ(edge[u]) > 1)
        minimize(dp[u][0],
            Best + Best1 + Best2);
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
        cin >> n >> A >> B;
        REP(i,1,n)
        {
            register int x, y, w;
            cin >> x >> y >> w;
            edge[x].pb(ii(y,w));
            edge[y].pb(ii(x,w));
        }
        memset(dp,0x3f,sizeof dp);
        if(n > 2)
        {
            dfs(1,1);
            cout << min(dp[1][0], dp[1][1]) + B;
        }
        else cout << 2LL * min(1LL * edge[1][0].se * A,1LL *  B);
    }

}

