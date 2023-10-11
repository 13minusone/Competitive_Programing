// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "DEBAISIEUNGAN"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 1e6 + 5;
const int MOD = 998244353;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n;
ll k, a, b, ans = 0, Fact[N];
void init(void)
{
    cin >> n >> k >> a >> b;
}
void add(ll &a, const ll &b)
{
    a += b;
    while(a >= MOD)a-= MOD;
}
void solve(int id, ll LCM)
{
    if(LCM == 0)
    {
        ll s = 1;
        FOR(j,id, n)
            s = 1LL * s * (b - a + 1) % MOD;
        add(ans, s);
        return;
    }
    if(id == n + 1)
    {
        if(LCM == 0)add(ans, 1);
        return;
    }
    for(ll i = a; i <= b; i++)
    {
        if(LCM == 0)solve(id + 1, LCM);
        else{
            int x = __gcd(LCM, i);
            solve(id + 1, 1LL * LCM * (i / x) % k);
        }
    }
}
void sub23()
{
    solve(1,1);
    cout << ans << endl;
}
ll Pow(ll a, int b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    ll t = Pow(a, b/2);
    if(b & 1)return 1LL * (1LL * t * t %MOD) * a %MOD;
    else return (1LL * t * t % MOD);
}
void sub4()
{
    ll x = (a - 1)/k + 1;
    ll o = b / k, id = 0;
    for(ll i = x; i <= o; i++){
        add(ans, (1LL * (Pow(b - a + 1 -id, n - 1) - 1) * Fact[n] + 1) % MOD);
       // cout << i << " " << ans << endl;
        id++;
    }
    cout << ans;
}
void process(void)
{
    Fact[0] = 1;
    FOR(i,1,n)
        Fact[i] = 1LL * Fact[i - 1] * i % MOD;
    if(k == 1)
    {
        ll s = b - a + 1;
        s %= MOD;
        ans = 1;
        FOR(i,1,n)
            ans = 1LL * ans * s % MOD;
        cout << ans << endl;
    }
    else if(b- a <= 30)sub23();
    else sub4();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


