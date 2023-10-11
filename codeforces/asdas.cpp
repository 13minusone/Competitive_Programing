/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "akarui"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second

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
        freopen(task ".ans", "w", stdout);
    }
    else if(fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(2e5) + 100;
const ll INF = 1e18;
const int mod = int(1e9) + 7;
void add(int &a, const int &b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}
int pw(int x, int y)
{
    int res = 1;
    while(y)
    {
        if(y & 1)
            res = 1LL*res*x%mod;
        x %= mod;
        x = 1LL*x*x%mod;
        y /= 2;
    }
    return res;
}
int n;
vec<int> a, b;
int fact[N], ifact[N];
struct FenwickTree
{
    int n;
    vec<ll> tree;

    FenwickTree(int _n = 0)
    {
        this->n = _n;
        tree.assign(n + 10, 0);
    }
    void update(int i, int val)
    {
        if(i == 0)
            return;
        for(; i <= n; i += ((i)&(-i)))
            tree[i] += val;
    }
    ll getSum(int i)
    {
        ll res = 0;
        for(; i > 0; i -= ((i)&(-i)))
             res += tree[i];
        return res;
    }
} bit, bit1;
void init()
{
    cin >> n;
    a = b = vec<int>(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
}
int C(int k, int n)
{
    return 1LL*((1LL*fact[n]*ifact[n - k])%mod)*ifact[k]%mod;
}
int dp[N], pref[N];
int calc(vec<int> p)
{
    bit = bit1 = FenwickTree(n);
    for(int i = 1; i <= n; i++)
    {
        bit1.update(i, 1);
        dp[i] = 0;
    }
    dp[0] = 0;
    int res = 0;
    int inv = 0;
    for(int i = 1; i <= n; i++)
    {
        int haventUsed = bit1.getSum(p[i] - 1)%mod;
        int tmp = 0;

        //suf - suf
        tmp = 1LL*C(2, n - i)*C(2, n - i)%mod;
        tmp = 1LL*tmp*fact[n - i - 2]%mod;
        tmp = 1LL*tmp*haventUsed%mod;
        cout << i << " " ;
        add(tmp, 1LL*pref[haventUsed - 1]*fact[n - i]%mod);
        add(res, tmp);
        cout << inv << " " ;
        //pref - suf
        tmp = inv;
        tmp = 1LL*tmp*haventUsed%mod;
        tmp = 1LL*tmp*fact[n - i]%mod;
        add(res, tmp);
        cout << tmp << " " ;
        //pref - pref
        tmp = 1LL*dp[i - 1]*fact[n - i]%mod;
        tmp = 1LL*tmp*haventUsed%mod;
        add(res, tmp);
        cout << tmp << endl ;
        dp[i] = i - 1 - bit.getSum(p[i]);
        add(dp[i], dp[i - 1]);

        add(inv, haventUsed);
        int k = (i - 1) - bit.getSum(p[i] - 1);
        add(inv, mod - k);
        cout << haventUsed << " " <<mod- k << endl;

        bit.update(p[i], 1);
        bit1.update(p[i], -1);
    }
    cout << dp[n] << endl;
    add(res, dp[n]);
    return res;
}
void process(const int &tc)
{
    int res = 0;
    if(n == 1)
    {
        cout << 0;
        return;
    }
    if(n == 2)
    {
        if((b[1] == 1)&&(b[2] == 2))
            cout << 0;
        else if((a[1] == 2)&&(a[2] == 1))
            cout << 1;
        else
            if((b[1] == 2)&&b[2] == 1)
            cout << 1;
        else
            cout << 0;
        return;
    }
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = 1LL*fact[i - 1]*i%mod;
    }
    ifact[N - 1] = pw(fact[N - 1], mod - 2);
    for(int i = N - 1; i >= 1; i--)
        ifact[i - 1] = 1LL*ifact[i]*i%mod;
    pref[0] = 0;
    for(int i = 1; i < N; i++)
    {
        pref[i] = pref[i - 1];
        add(pref[i], i);
    }
    res = calc(b);
    //cout << res << endl;
    add(res, mod - calc(a));
    bit = FenwickTree(n);
    for(int i = n; i >= 1; i--)
    {
        add(res, (int)(bit.getSum(a[i] - 1)%mod));
        bit.update(a[i], 1);
    }
    cout << res;
}
int main()
{
    fastio();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}

