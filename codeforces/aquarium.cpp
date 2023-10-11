/// KoJa
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#define task "aquarium"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define FOR(i,a,b) for(int i = a; i <= b;i++)

typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(1e6) + 1;
const ll INF = 1e18;
int n, m, cnt = 0;
vector<int>a[2][2*N];
vector<int>d[N];
vector<char>gh[N];
int par[2*N];
ii luu[2*N];
vector<tuple<int,int,int>>edge;
int root(int u)
{
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}
bool join(int u, int v)
{
    if( (u = root(u)) == (v = root(v)))return false;
    if(-par[u] < -par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
char c;
void init()
{
    cin >> n >> m;
    FOR(i,0,n){
        d[i].resize(m+1);
        gh[i].resize(m+1);
        FOR(j,0,1)
        a[j][i].resize(m+1);
    }
    FOR(i,1,2*n*m)par[i] = -1;
    FOR(i,1,n)
        FOR(j,1,m)
        {
            cin >> c;
            gh[i][j] = c;
            a[0][i][j] = ++cnt;
            a[1][i][j] = ++cnt;
            luu[cnt] = ii(i,j);
            luu[cnt-1] = ii(i,j);
            if(a[0][i][j-1] != 0){
                join(cnt-1,a[1][i][j-1]);
                }
            if(c == '/')
            {
                d[i][j] = 1;
                if(a[0][i-1][j] != 0 && !d[i-1][j])
                    join(a[0][i-1][j],cnt-1);
                else if(a[0][i-1][j] != 0 && d[i-1][j])
                    join(a[1][i-1][j],cnt-1);
            }
            else
            {
                if(a[1][i-1][j] != 0 && d[i-1][j])
                    join(a[1][i-1][j],cnt);
                else if(a[1][i-1][j] != 0 && !d[i-1][j])
                   join(a[0][i-1][j],cnt);
            }
        }
    FOR(i,1,n)
        FOR(j,1,m)
        {
            int w;
            cin >> w;
            edge.pb({w,a[0][i][j],a[1][i][j]});
        }
    sort(SZ(edge));
    ll s = 0;
    int node = cnt;
    for(auto [w,x,y]  : edge)
    {
        //cout << i.x << " "<< i.y << " "<< i.w << endl;
        if(join(x, y)){
                s += w;
                if(luu[x] == luu[y])
                gh[luu[x].fi][luu[x].se] = '.';
        }
    }
    cout << s <<endl;
    FOR(i,1,n){
        FOR(j,1,m)
            cout << gh[i][j];
    cout << endl;
    }
}
void process()
{
}
int main()
{
    fastio();
    init();
    process();
    return 0;
}
