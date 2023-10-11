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
ll n, w, m, na, nb,x,y,z;
ll cnta[N], cntb[N], par[3*N];
ll ans = 0;
ll root(int u)
{
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}
void join(int u, int v, int z)
{
    if( (u = root(u)) == (v = root(v)))return;
    if(-par[u] < -par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    if(z == w){
        ans += 1LL*cnta[u] * cntb[v];
        ans += 1LL*cntb[u] * cnta[v];
    }
    cnta[u] += cnta[v];
    cntb[u] += cntb[v];
    return;
}
struct Data
{
    ll x, y;
    ll z;
    Data(ll _x =0, ll _y = 0, ll _z = 0)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};
bool cmp(Data a, Data b)
{
    return a.z < b.z;
}
vector<Data>vec;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> w >> na >> nb;
    FOR(i,1,m)
    {
        cin >> x >> y >> z;
        if(z <= w)vec.pb(Data(x,y,z));
        par[i] = -1;
    }
    FOR(i,1,na){
        cin >> x;
        cnta[x]++;
    }
    FOR(i,1,nb)
    {
        cin >> x;
        cntb[x]++;
    }
    sort(all(vec),cmp);
    for(Data i : vec)
    {
        join(i.x,i.y,i.z);
    }
    cout << ans;
}

