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

const int N = 1e3;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m, maxx = 0;
int par[N*N+1], id[N+2][N+2],cnt = 0;
int root(int u)
{
    return (par[u]< 0 ? u : par[u] = root(par[u]));
}
void join(int u, int v)
{
    if( (u = root(u)) == (v = root(v)))return;
    if(-par[u] < -par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    maximize(maxx, -par[u]);
    return ;
}
char a[N+2][N+2];
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
    FOR(i,1,n)
    {
        FOR(j,1,m)id[i][j] =++cnt;
    }
    FOR(i,1,n*m)par[i] = -1;
    FOR(i,1,n)
    {
       FOR(j,1,m){
           cin >> a[i][j];
            if(a[i][j] == '0')continue;
            if(a[i-1][j] == '1')
                join(id[i-1][j],id[i][j]);
            if(a[i][j-1] == '1')
                join(id[i][j-1],id[i][j]);
        }
    }
    int q;
    cin >> q;
    short x,y;
    while(q--)
    {
        cin >> x >> y;
        if(a[x][y] == '1'){
                cout << maxx << endl;
                continue;
        }
        if(a[x-1][y] == '1')join(id[x-1][y],id[x][y]);
        if(a[x][y-1] == '1')join(id[x][y-1],id[x][y]);
        if(a[x][y+1] == '1')join(id[x][y+1],id[x][y]);
        if(a[x+1][y] == '1')join(id[x+1][y],id[x][y]);
        a[x][y] = '1';
        cout << maxx << endl;
    }
}

