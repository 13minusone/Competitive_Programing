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

const int N = 2e5 + 5;
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;

int n, a[N], b[N];
ll fact[N], ifact[N];
ll powe(ll a, ll b)
{
    if(b == 0)return 1;
    if(b == 1)return a;
    int t = powe(a,b/2);
    if(b&1)return (1LL* ((1LL * t * t)%mod) * a)%mod;
    else return (1LL *t * t)%mod;
}
void add(ll &a, ll b)
{
    a += b;
    if(a >= mod)a-=mod;
}
void sub(ll &a, ll b)
{
    a -= b;
    a+= mod;
    if(a >= mod)a-=mod;
}
struct BIT
{
    int n;
    vector<ll>vec;
    BIT(int _n = 0)
    {
        n = _n;
        vec.assign(n+10, 0);
    }
    void upd(int i,int val)
    {
        if(i <= 0)return;
        for(;i <= n; i += (i & (-i)))vec[i] += val;
    }
    ll get(int i)
    {
        if(i <= 0)return 0;
        ll ans = 0;
        for(; i > 0; i -= (i & (-i)))ans += vec[i];
        return ans;
    }
};
BIT tree, dd ;
ll C(int a, int b)
{
    if(b < a)return 0;
    return ( 1LL * ((1LL * fact[b] * ifact[a] )%mod) * ifact[b-a])%mod;
}
ll div2 = powe(2,mod-2);
int d[N];
ll calca()
{
     ll res = 0, pref = 0, prefsuf = 0, preffix = 0, suffix = 0, presuf = 0, inv = 0, tru  = 0;
    tree = BIT(n);
    dd = BIT(n);
    FOR(i,1,n)dd.upd(i,1);
    FOR(i,1,n){
        int noww = a[i];
        ll C2 = C(2,n-i), getn = tree.get(n);
        suffix = 0, presuf = 0;
        ll x = dd.get(noww-1)%mod;
        //suf
        suffix = 0;
        add(suffix, 1LL * (1LL *(1LL *C2 * C2 %mod) * fact[n-i-2]%mod) * x%mod) ;
        add(suffix, 1LL * fact[n-i]* ((1LL * x*(x-1)%mod)*div2%mod)%mod) ;
        //pref  -suf
        presuf = (1LL * (1LL * inv * fact[n-i]%mod) * x)%mod;
        add(inv, x);
        add(inv, mod - ((i-1) - tree.get(noww-1)));
        //pref
        add(res, 1LL * (1LL * pref * fact[n-i]%mod) * x%mod);
        //cout <<i << " " <<  pref * fact[n-i] * x;
        add(res, suffix);
        add(res, presuf);

        add(pref, i-1-tree.get(noww));
        tree.upd(noww,1);
        dd.upd(noww,-1);
        //cout  << " " << suffix << " " << presuf << endl;
    }
    add(res, pref);
    return res;
}
ll calcb()
{
    ll res = 0, pref = 0, prefsuf = 0, preffix = 0, suffix = 0, presuf = 0, inv = 0, tru  = 0;
    tree = BIT(n);
    dd = BIT(n);
    FOR(i,1,n)dd.upd(i,1);
    FOR(i,1,n){
        int noww = b[i];
        ll C2 = C(2,n-i), getn = tree.get(n);
        suffix = 0, presuf = 0;
        ll x = dd.get(noww-1);
        //suf
        suffix = 0;
        add(suffix, (1LL * ((1LL *((1LL *C2 * C2) %mod) * fact[n-i-2])%mod) * x)%mod) ;
        add(suffix, 1LL * fact[n-i]* (((1LL * x*(x-1)%mod)*div2)%mod)%mod) ;
        //pref  -suf
        presuf = (1LL * (1LL * inv * fact[n-i])%mod * x)%mod;
        add(inv, x);
        add(inv, mod - ((i-1) - tree.get(noww-1)));
        //pref
        add(res, 1LL * (1LL * pref * fact[n-i]%mod) * x%mod);
        //cout <<i << " " <<  pref * fact[n-i] * x;
        add(res, suffix);
        add(res, presuf);

        add(pref, i-1-tree.get(noww));
        tree.upd(noww,1);
        dd.upd(noww,-1);
        //cout  << " " << suffix << " " << presuf << endl;
    }
    add(res, pref);
    return res;
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
    FOR(i,1,n){
        cin >> a[i];
    }
    FOR(i,1,n)cin >> b[i];
    fact[0] = 1;
    FOR(i,1,n){
        fact[i] = (1LL * fact[i-1] * i)%mod;
    }
    ifact[n]= powe(fact[n],mod-2);
    FD(i,n,1)
        ifact[i-1] = (1LL * ifact[i]*i)%mod;
   // cout << C(2,2) << endl;
    ll fa = calca();
    ll fb = calcb();
    ll res = 0;
    add(res, fb);
    add(res, mod - fa);
    tree = BIT(n);
    FD(i,n,1)
    {
        add(res, tree.get(a[i]));
        tree.upd(a[i],1);
    }
    cout << res << endl;
}

