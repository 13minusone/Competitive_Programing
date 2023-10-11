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
//const int block = 488;
int n,m,hi[N],par[N][25];
vector<int>edge[N];
void dfs(int u, int pre)
{
    FOR(i,1,20)par[u][i] = par[ par[u][i-1]][i-1];
    for(int v : edge[u])if(v != pre)
    {
        hi[v] = hi[u]+1;
        par[v][0] = u;
        dfs(v,u);
    }
}
int lca(int u, int v)
{
    if(hi[u] < hi[v])swap(u,v);
    FD(i,20,0)
    {
        if(hi[par[u][i]] >= hi[v])u = par[u][i];
    }
    if(u == v)return u;
    FD(i,20,0)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
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
    cin >> n >> m;
    FOR(i,1,n-1)
    {
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    hi[1]=1;
    par[1][0]=1;
    dfs(1,1);
   while(m--)
   {
       int x, y, z;
       cin >> x >> y >> z;
       int lca1 = lca(y,z);
       int lca2 = lca(x,z);
       int lca3 = lca(x,y);
       //cout << lca1 << " " << lca2 << " "<< lca3 << endl;
       ii a = ii(abs(hi[lca1] - hi[x]),lca1);
       ii b ,c;
       if(lca(x,lca1) == lca1){
            b = ii(abs(hi[lca2] - hi[x]),lca2);
            c = ii(abs(hi[lca3] - hi[x]),lca3);
            minimize(b,c);
            cout << b.se << endl;

       }
       else cout << lca1 << endl;
   }
}
