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

const int N = 1e2 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m, s, t;
int dp[N][10005];
struct Data
{
    int v, c, d;
    Data(int _v = 0, int _c = 0, int _d = 0)
    {
        v = _v;
        c = _c;
        d = _d;
    }
};
vector<Data>edge[N];
void dist()
{
    queue<Data>qu;
    qu.push(Data(s,0,0));
    memset(dp,0x3f,sizeof dp);
//    cout << s <<" " << t << endl;
    dp[s][0] = 0;
    while(!qu.empty())
    {
        Data x = qu.front();
        qu.pop();
        if(dp[x.v][x.c] < x.d)continue;
        for(Data u : edge[x.v])
        {
            if(x.c +u.c <= 10000 && minimize(dp[u.v][x.c + u.c], x.d +u.d ))
            {
                //cout << u.v << " " << u.c << " " << dp[u.v][x.c+u.c] << endl;
                qu.push(Data(u.v, x.c + u.c, x.d + u.d));
            }
        }
    }
    int minn = N * 50100,ans  = 0;
    FOR(i,0,10000)
    {
        //cout << dp[t][i] << endl;
        if(dp[t][i] < minn && dp[t][i] <= 10000)ans++;
        minimize(minn,dp[t][i]);
    }
    cout << ans;
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
    cin >> n >> m >> s >> t;
    FOR(i,1,m)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        edge[u].pb(Data(v,c,d));
        edge[v].pb(Data(u,c,d));
    }
    dist();
}

