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

const int N = 1e3 + 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
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
int n, m, x, y, z;
vector<Data>edge;
int par[N];
ll root(int u)
{
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}
int s = n-1;
void join(int u, int v)
{
    if( (u = root(u)) == (v = root(v)))return;
    if(-par[u] < -par[v])swap(u,v);
    par[u] += par[v];
    par[v] = u;
    s--;
    return;
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
    FOR(i,1,m)
    {
        cin >> x >> y >> z;
        edge.pb(Data(x,y,z));
    }
    sort(all(edge), cmp);
    int minn = mod;
    ii ans;
    REP(i,0,m)
    {
        int r= i;
        s = n;
        memset(par,-1,sizeof par);
        while(r < m)
        {
            join(edge[r].x,edge[r].y);
            if(s == 1)break;
            r++;
        }
        if(minn > edge[r].z-edge[i].z+1 && r < m)
        {
            ans = ii(edge[i].z,edge[r].z);
            minn = edge[r].z-edge[i].z+1;
        }
        //cout << i << " " << r << endl;
    }
    cout << ans.fi << " " << ans.se;
}

