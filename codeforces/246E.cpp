// Author : Nyanpasuuuuu
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
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, col[N], ans[N], m;
bool root[N];
string s[N];
vector<int>edge[N];
vector<string>val;
vector<set<int>>cnt[N];
vector<ii>query[N];
void dfs(int u, int pre)
{
    for(int v : edge[u])if(v != pre)
    {
        dfs(v,u);
        if(SZ(cnt[u]) < SZ(cnt[v]))swap(cnt[u], cnt[v]);
        for(int i = SZ(cnt[v]) - 1, j = SZ(cnt[u]) - 1; i >= 0 ; i--, j--)
        {
            for(auto x : cnt[v][i])cnt[u][j].insert(x);
        }
    }
    set<int>add;
    add.insert(col[u]);
    cnt[u].pb(add);
    for(ii v : query[u])
    {
        int Sz = SZ(cnt[u]);
        //cout << v.fi << "  " << v.se << " " << Sz << " " << u << endl;
        if(v.fi >= Sz)ans[v.se] = 0;
        else ans[v.se] = SZ(cnt[u][Sz - v.fi - 1]);
    }
}
void init(void)
{
    cin >> n;
    FOR(i,1,n)
    {
        register int u;
        cin >> s[i] >> u;
        if(u == 0)root[i] = 1;
        else edge[u].pb(i);
        val.pb(s[i]);
    }
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    FOR(i,1,n)
        col[i] = lower_bound(all(val), s[i]) - val.begin() + 1;
}
void process(void)
{
    cin >> m;
    FOR(i,1,m)
    {
        register int x, k;
        cin >> x >> k;
        query[x].pb(ii(k, i));
    }
    FOR(i,1,n)
        if(root[i])dfs(i,-1);
    FOR(i,1,m)
        cout << ans[i] << endl;
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
    while(t--)
    {
        init();
        process();
    }

}

