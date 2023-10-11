/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "minimum"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
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
const int N = int(5e6) + 1;
const ll mod = 1e18;
int n, a[N], x, y;
ll s[N];
void init()
{
    cin >> n >> x >> y;
    FOR(i,1,n){
        cin >> a[i];
        s[i] =  s[i-1] + a[i];
    }
    ii maxfi = ii(-mod,0), res, maxse = ii(-mod,0);
    ll ans = -mod;
    for(int i = n;i >= 1; i--)
    {
        if(a[i] < x)
                maxfi =maxse =  ii(-mod,0);
        else{
            if(maxfi.fi < s[i])
                maximize(maxse, ii(s[i], i));
            if(a[i] >= x && a[i] <= y)
                if(maximize(maxfi,maxse))
                    maxse = ii(-mod,0);
            if(maximize(ans, maxfi.fi - s[i-1]))
                res = ii(i,maxfi.se);
        }
//        cout << i << endl;
//        cout << maxfi.fi << " " << maxfi.se << endl;
//        cout << maxse.fi << " " << maxse.se << endl;
    }
    cout << ans << endl;
    cout << res.fi << " " << res.se;
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
