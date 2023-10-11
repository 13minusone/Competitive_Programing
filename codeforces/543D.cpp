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

const int N = 2e5 + 5;
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;

ll in[N], out[N];
vector<int>edge[N];
int n, x;
ll powe(ll a, ll b)
{
    if(b == 0)return 1;
    if(b == 1) return a;
    ll t = powe(a,b/2)%mod;
    if(b&1)return (((1LL*a*t)%mod)*t)%mod;
    else return (1LL*t*t)%mod;
}
void precalc(int u, int pre)
{
   in[u] = 1;
    for(int v : edge[u])if(v != pre)
    {
        precalc(v,u);
        in[u] =(1LL * (in[u]%mod) *  ((in[v] + 1)%mod))%mod;
    }
}
void solve(int u,int pre)
{
    for(int v : edge[u])if(v != pre)
    {
        //out[v] =(1LL*out[u] *  (in[u]/(in[v] + 1)) );
        out[v] =(( 1LL*out[u] *  ((1LL*(in[u]%mod) * powe(in[v]+1,mod-2))%mod))%mod )%mod;
        cout << out[u] << " "<< (in[u]/(in[v] + 1)) << " " << v << endl;
        solve(v,u);
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
    FOR(i,2,n)
    {
        cin >> x;
        edge[x].pb(i);
    }
    //cout << powe(2,2) << endl;
    in[1] = 1;
    precalc(1,1);
    out[1] = 1;
    solve(1,1);
    //FOR(i,1,n)cout <<out[i] << " "<< in[i] <<endl ;
}

