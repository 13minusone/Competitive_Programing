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

const int N = 5e2 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m, nearu[N];
bool a[N][N];
string s;
struct Data
{
    int x, y, a, b;
    Data(int _x = 0, int _y = 0, int _a = 0, int _b = 0)
    {
        x = _x;
        y = _y;
        a = _a;
        b = _b;
    }
};
bool cmp(Data a, Data b)
{
    return abs(a.x - a.a + a.b - a.y)
        < abs(b.x - b.a +b.b - b.y);
}
vector<Data>vec;
int par[N * N], id[N][N], com = 0, cnt = 0;
int root(int u)
{
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}
bool join(int u, int v)
{
    if( (u = root(u) ) == ( v = root(v) ) )return false;
    if(-par[u] < - par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    com--;
    return true;
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
    FOR(i,1,n)
    {
        cin >> s;
        s = ' ' + s;
        int nearl = 0;
        FOR(j,1,m){
            a[i][j] = int(s[j] - '0');
            id[i][j] = ++cnt;
            par[cnt]= -1;
            if(a[i][j] == 1)
            {
                com++;
                if(nearl != 0)vec.pb(Data(i,nearl, i,j));
                if(nearu[j] != 0)vec.pb(Data(nearu[j],j,i,j));
                nearl = j;
                nearu[j] = i;
            }
        }
    }
    sort(all(vec), cmp);
    ll sum = 0;
    for(Data x : vec)
    {
        //cout << x.x << " " << x.y << " " << x.a << " " << x.b << endl;
        if(join(id[x.x][x.y],id[x.a][x.b]))
                //cout << x.x << " " << x.y << " " << x.a << " " << x.b << endl;
            sum += abs(x.x - x.a + x.b - x.y)-1;
    }
    if(com > 1)cout << -1;
    else cout << sum << endl;
}

