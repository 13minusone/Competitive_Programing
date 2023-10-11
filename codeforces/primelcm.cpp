/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "primelcm"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define fi first
#define se second
#define FOR(i,a,b) for(int i = a; i <= b;i++)
typedef long long ll;
typedef pair<ll, int> ii;
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
int N = int(1e6) + 1;
const int INF = 1e7;
const ll mod = 998244353;
bool d[INF +2];
int n;
ll ans[INF+2];
vector<int>vec;
vector<ii>a;
void etheranes()
{
    d[0] = 1;
    FOR(i,2,INF)
    {
        if(!d[i])
        {
            vec.pb(i);
            for(ll j =  2*i; j <= INF; j+= i)d[j] = 1;
        }
    }
}
ll powe(ll a, ll b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    ll t = powe(a,b/2)%mod;
    if(b&1)
        return 1LL * (1LL * t * t%mod) * a %mod;
    else
        return (1LL * t * t)%mod;
}
void init()
{
    etheranes();
    //cout << vec.size();
    a.pb(ii(1,1));
    for(int i : vec)
    {
        ll x = i;
        FOR(j,1,47)
        {
            if(x > 1LL * INF *INF/i)break;
            x *= i;
            a.pb(ii(x,i));
        }
    }
    sort(SZ(a));
    int ok = a.size();
    ans[0] = 1;
    FOR(i,1,ok-1)
    {
        if(i > 0)ans[i] = (1LL * ans[i-1] * a[i].se)%mod;
        //if(i <= 10)cout << ans[i] << endl;
    }
    cin >> n;
    FOR(i,1,n)
    {
        ll x;
        cin >> x;
        //cout << i << endl;
//        for(int o : vec)
//        {
//            if(o > x)break;
//            int k = lower_bound(SZ(a[o]), x)-a[o].begin();
//            if(k == 0)break;
//            ans *= powe(o, k-1);
//            ans %= mod;
//            cout << o << " " << k << endl;
//        }
//        cout << ans << " " ;
    ll l = 0, r= ok -1, k;
    while( l <= r)
    {
        ll mid = (l+r) >> 1;
        if(a[mid].fi <=  x)
        {
            k = ans[mid];
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << k << " " ;
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

