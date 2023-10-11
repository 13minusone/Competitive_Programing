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
int n, hi[N], par[N];
bool have[N];
vector<int>edge[N];
void trace(int u, int pre)
{
    have[u] = 1;
    for(int v : edge[u])if(v != pre)
    {
        if(hi[u] == hi[v] + 1){
            trace(v, u);
            break;
        }
    }
}
void dfs(int u, int pre)
{
    for(int v : edge[u])if(v != pre)
    {
        par[v] = u;
        dfs(v, u);
        maximize(hi[u], hi[v]);
    }
    hi[u]++;
}
void init(void)
{
    cin >> n;
    REP(i,1,n)
    {
        register int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
}
void process(void)
{
    queue<ii>q;
    q.push(ii(0,1));
    int maxx = 0, root = 1;
    while(!q.empty())
    {
        ii x = q.front();
        q.pop();
        have[x.se] = 1;
        if(maximize(maxx, x.fi))
            root = x.se;
        for(int v : edge[x.se])if(!have[v])
            q.push(ii(x.fi + 1, v));
    }
    dfs(root,-1);
    priority_queue<ii>qu;
    memset(have, 0, sizeof have);
    int ans = 0;
    FOR(i,1,n)
        qu.push(ii(hi[i], i));
    cout << 1 << " " ;
    FOR(i,2,n)
    {
        while(!qu.empty() && have[qu.top().se])qu.pop();
        if(!qu.empty())
        {
            ans += qu.top().fi;
            //cout << qu.top().fi << " " << qu.top().se << endl;
            trace(qu.top().se,par[qu.top().se]);
        }
        cout << ans << " " ;
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


