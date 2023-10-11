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

const int N = 1e3 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, d[N] ,sz[N], q;
vector<int>edge[N];
ll f[N][N][2];
bool vis[N];
void dfs(int u, int pre)
{
    vis[u] = 1;
    f[u][0][0] = 0;
    if(u != 0)sz[u]  =1;
    for(int v : edge[u])if(v != pre && !vis[v])
    {
        dfs(v,u);
        FD(j,sz[u],0)
            FD(k,sz[v], 0)
            {
                minimize(f[u][j + k][0], f[u][j][0] + min(f[v][k][0], f[v][k][1]));
                minimize(f[u][j + k][1], f[u][j][1] + min(f[v][k][0], f[v][k][1]));
                if(j < sz[u]);
                minimize(f[u][j + 1 + k][1], f[u][j][0] + d[u] + f[v][k][1]);
                if(k < sz[v] && j < sz[u])
                minimize(f[u][j + 2 + k][1], f[u][j][0] + d[u] + d[v] + f[v][k][0]);
                if(k < sz[v])
                minimize(f[u][j + 1 + k][1], f[u][j][1] + d[v] + f[v][k][0]);
            }
        sz[u] += sz[v];
    }
}
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
        cin >> d[i];
    FOR(i,1,m)
    {
        register int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}
void process(void)
{
    memset(f,0x3f,sizeof f);
    f[0][0][0] = 0;
    FOR(i,1,n)if(!vis[i])
    {
        edge[0].pb(i);
        dfs(0,-1);
    }
   cin >> q;
//   FOR(i,0,n)
//    cout << i << " " << f[0][i][0] << endl;
   while(q--)
   {
       register int x;
       cin >> x;
       int k;
       FD(i,n, 0)
            if(f[0][i][0] <= x){
                k = i;
                break;
            }

       cout << k << endl;
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}

