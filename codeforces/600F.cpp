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

const int N = 1e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int a, b, m, d, u[N], v[N], deg[2*1001], color[2*1001][1001], id[2*1001][1001], res[N];
void dfs(int x, int y,int i, int col1, int col2, bool par = 1 ,bool t = 1)
{
    if(t)
    {
        if(!par)
        {
            int u = color[y][col1];
            int i = id[y][col1];
            color[y][col1] = 0, id[y][col1] = 0;
            color[u][col1] = 0, id[u][col1] = 0;
            dfs(y, u, i, col1, col2, par ^ 1, color[u][col2]);
        }
        else
        {
            int u = color[y][col2];
            int i = id[y][col2];
            color[y][col2] = 0, id[y][col2] = 0;
            color[u][col2] = 0, id[u][col2] = 0;
            dfs(y, u, i, col1, col2,  par ^ 1, color[u][col1]);
        }
    }
    if(!par)
    {
        res[i] = col1;
        color[x][col1] = y;
        color[y][col1] = x;
        id[x][col1] = id[y][col1] = i;
    }
    else
    {
        res[i] = col2;
        color[x][col2] = y;
        color[y][col2] = x;
        id[x][col2] = id[y][col2] = i;
    }
}
void solve()
{
    FOR(i,1,m)
    {
        int x = u[i], y = v[i], col1 = 0, col2 = 0;
        FOR(j,1,d)
        {
            if(!color[x][j] && !color[y][j])
            {
                color[x][j] = y;
                color[y][j] = x;
                res[i] = j;
                id[x][j] = id[y][j] = i;
                goto cont;
            }
        }
        FOR(j,1,d)
        {
            if(color[x][j] && !color[y][j])col1 = j;
            if(!color[x][j] && color[y][j])col2 = j;
        }
        dfs(x,y, i,col1,col2);
        cont:;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
    cin >> a >> b >> m;
    FOR(i,1,m)
    {
        cin >> u[i] >> v[i];
        v[i] += a;
        deg[u[i]]++, deg[v[i]]++;
        maximize(d,max(deg[u[i]], deg[v[i]]));
    }
    solve();
    cout << d << endl;
    FOR(i,1,m)cout << res[i] << " " ;
}
 
