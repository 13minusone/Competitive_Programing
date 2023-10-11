// Onegai no bug
// Author : Nyanpasuuuuu
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

const int N = 1e6 + 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n, hi[N], k, d[N];
ii cnt[N];
vector<int>edge[N];
void dfs(int u, int pre)
{
    for(int v : edge[u]) if(v != pre)
    {
        hi[v] = hi[u] + 1;
        dfs(v, u);
        if(cnt[v].fi <= hi[u])
        {
            minimize(cnt[u].fi, cnt[v].fi);
            cnt[u].se += cnt[v].se;
        }
    }
    if(u != 1 &&SZ(edge[u]) == 1)
    {
        d[u] = 1;
        cnt[u] = ii(hi[u]-k, 1);
    }
}
void calc(int u, int pre)
{
    for(int v : edge[u])if(v != pre)
    {
        calc(v,u);
        int tmp = cnt[u].se;
        if(cnt[v].fi <= hi[u])tmp -= cnt[v].se;
        maximize(d[u], tmp + d[v]);
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
    cin >> n >> k;
    FOR(i,2,n)
    {
        register int x;
        cin >> x;
        edge[i].pb(x);
        edge[x].pb(i);
        cnt[i] = ii(mod, 0);
    }
    hi[1] = 1;
    dfs(1,-1);
    calc(1, -1);
    //cout << cnt[1].se << endl;
    cout << d[1];
}

