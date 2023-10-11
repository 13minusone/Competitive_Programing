///KoJa
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define vec vector
#define fi first
#define se second
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(n) (1LL << (n))
#define MASK(x, i) (((x) >> (i))&1)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
struct Points
{
    ll x, y;
    Points(){}
    Points(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }
    Points operator - (const Points &other) const { return Points(x - other.x, y - other.y);}
    ll operator * (const Points &other) const { return x * other.y - y * other.x;}
    ll triangle(const Points &b, const Points &c)
    {
        return (*this - b) * (*this - c);
    }
};
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if(fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if(fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = 105;
const ll INF = 1e18;
int n;
ll a[N];
void init()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void process(int tc = 0)
{
    bool ok = 1;
    for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) if(__gcd(a[i], a[j]) != 1) ok = 0;
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    fastio();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
