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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n;
vector<ii>edge[N];
ll Furthest[N], ans = 0, sum = 0, Furthestout[N], Max2in[N];
void dfs(int u, int pre)
{
    vector<ll>vec;
    for(ii &v : edge[u])if(v.fi != pre)
    {
        dfs(v.fi, u);
        maximize(Furthest[u], Furthest[v.fi] + v.se);
        vec.push_back(Furthest[v.fi] + v.se);
    }
    sort(all(vec));
    Max2in[u] = 0;
    if(SZ(edge[u]) == 2)Max2in[u] = vec[SZ(vec) - 1];
    else if(SZ(edge[u]) >= 3)Max2in[u] = vec[SZ(vec) - 1] + vec[SZ(vec) - 2];
    for(ii &v : edge[u])if(v.fi != pre)
        maximize(Max2in[u], Max2in[v.fi]);
}
void solve(int u, int pre, ll Longest)
{
    ll Long[5];
    pair<ll,ll> MaxOut = ii(0,0);
    Long[1] = Long[2] = Long[3] = 0;
    Long[4] = Longest;
    for(ii &v : edge[u])if(v.fi != pre)
    {
        if(Furthest[v.fi] + v.se > Long[4]){
            FOR(i,1,3)
                Long[i] = Long[i + 1];
            Long[4] = Furthest[v.fi] + v.se;
        }
        else if(Furthest[v.fi] + v.se > Long[3])
        {
            FOR(i,1,2)
                Long[i] = Long[i + 1];
            Long[3] = Furthest[v.fi] + v.se;
        }
        else if(Furthest[v.fi] + v.se > Long[2])
        {
            Long[1] = Long[2];
            Long[2] = Furthest[v.fi] + v.se;
        }
        else maximize(Long[1], Furthest[v.fi] + v.se);

        if(Max2in[v.fi] > MaxOut.fi){
            MaxOut.se = MaxOut.fi;
            MaxOut.fi = Max2in[v.fi];
        }
        else maximize(MaxOut.se, Max2in[v.fi]);
    }
    minimize(ans, sum - Long[1] - Long[2] - Long[3] - Long[4]);
    //cout << u << " " << Long[1] << " " << Long[2] << " " << Long[3] << " " << Long[4] << endl;
    for(ii &v : edge[u])if(v.fi != pre)
    {
        Furthestout[v.fi] = Furthestout[u];
        if(Max2in[v.fi] == MaxOut.fi)maximize(Furthestout[v.fi], MaxOut.se);
        else maximize(Furthestout[v.fi], MaxOut.fi);
        ll Farthest = 0;
        if(Furthest[v.fi] + v.se == Long[4]){
            maximize(Furthestout[v.fi], Long[3] + Long[2]);
            Farthest = Long[3];
        }
        else if(Furthest[v.fi] + v.se == Long[3])
        {
            maximize(Furthestout[v.fi], Long[4] + Long[2]);
            Farthest = Long[4];
        }
        else{
            maximize(Furthestout[v.fi], Long[4] + Long[3]);
            Farthest = Long[4];
        }
        minimize(ans, sum - 2 * v.se - Furthestout[v.fi] - Max2in[v.fi]);
       // cout << u << " " << v.se << " "<< Furthestout[v.fi] << " " << Max2in[v.fi] << endl;
        solve(v.fi, u, Farthest + v.se);
    }
}
void init(void)
{
    cin >> n;
    FOR(i,1,n - 1)
    {
        register int u, v, w;
        cin >> u >> v >> w;
        edge[u].pb(ii(v,w));
        edge[v].pb(ii(u,w));
        sum += w;
    }
    sum *= 2;
    ans = sum;
}
void process(void)
{
    dfs(1,-1);
    solve(1,-1,0);
    cout << ans;
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


