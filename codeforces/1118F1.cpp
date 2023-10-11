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

const int N = 3e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n, in[N][3],out[N][3], color[N] ,ans = 0;
vector<int>edge[N];
void dfs(int u, int pre)
{
    in[u][color[u]]++;
    for(int v : edge[u]) if(v != pre)
    {
        dfs(v,u);
        in[u][1] += in[v][1];
        in[u][2] += in[v][2];
    }
}
void solve(int u, int pre)
{
    for(int v : edge[u]) if(v != pre)
    {
        out[v][1] = out[u][1] + in[u][1] - in[v][1];
        out[v][2] = out[u][2] + in[u][2] - in[v][2];
        //cout << v << " "<< out[v][1] << " " << out[v][2] << endl;
        if(out[v][1] * out[v][2] == 0 && in[v][1] * in[v][2] == 0)ans++;
        solve(v, u);
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
    FOR(i,1,n)cin >> color[i];
    REP(i,1,n)
    {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    dfs(1,1);
    solve(1,1);
    cout << ans;

}
