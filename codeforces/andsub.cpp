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

const int N = 1e6;
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;

ll s[N+2], f[N+2], cnt[N+2], a[N+2], n, maxx = 0;
void add(ll &a, ll b)
{
    a+= b;
    if(a >= mod)a-=mod;
}
vector<int>vec;
ll powe(int a, int b)
{
    if(b ==  1)return a;
    if(b == 0)return 1;
    ll t = powe(a,b/2);
    if(b&1)return (((1LL*t*t)%mod)*a)%mod;
    else return (1LL*t*t) %mod;
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
    FOR(i,1,n)
    {
        cin >> a[i];
        maximize(maxx,a[i]);
    }
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
    ll res = (1LL << 10);
    if(maxx <= 1)res = maxx;
    FOR(i,1,n)
    {
        int v = a[i];
        add(f[v],1);
        REP(j,0,res)
        {
            add(f[v&j],f[j]%mod);
        }

    }
    cout << (1LL*f[0] * powe(2,mod-2))%mod << endl;
}
