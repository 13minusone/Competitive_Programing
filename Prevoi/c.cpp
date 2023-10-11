///KoJa
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define vec vector
#define fi first
#define se second
#define BIT(n) (1LL << (n))
#define MASK(x, i) (((x) >> (i))&1)
#define pb push_back
#define mp make_pair
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
typedef long long ll;
typedef pair<int, int> ii;

template<class T>
bool maximize(T &a, const T &b) { return ((a < b) ? (a = b, 1) : 0);}
template<class T>
bool minimize(T &a, const T &b) { return ((a > b) ? (a = b, 1) : 0);}
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
    ll triangle(const Points &b, const Points &c) const {return (*this - b) * (*this - c);}
};
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if(fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".ans", "w", stdout);
    }
}
const int N = 105;
const ll INF = 1e18;
int n, a[N][N], b[N][N];
void init()
{
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        cin >> a[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        cin >> b[i][j];
}
void sub2()
{
    vec<ii> op;
    int res = 2 * n + 10;
    for(int i = 0; i < n; i++)
    {
        op.pb(ii(0, i));
        op.pb(ii(1, i));
    }
    for(int mask = 0; mask < BIT(2 * n); mask++)
    {
        if(res <= __builtin_popcount(mask)) continue;
        for(int i = 0; i < 2 * n; i++) if(MASK(mask, i))
        {
            if(op[i].fi == 0)
            {
                for(int j = 0; j < n; j++) a[op[i].se][j] *= -1;
            }
            else
            {
                for(int j = 0; j < n; j++) a[j][op[i].se] *= -1;
            }
        }
        bool ok = 1;
        for(int i = 0; ((i < n) && (ok)); i++) for(int j = 0; j < n; j++)
        {
            if(a[i][j] != b[i][j])
            {
                ok = 0;
                break;
            }
        }
        if(ok) res = min(res, __builtin_popcount(mask));
        for(int i = 0; i < 2 * n; i++) if(MASK(mask, i))
        {
            if(op[i].fi == 0)
            {
                for(int j = 0; j < n; j++) a[op[i].se][j] *= -1;
            }
            else
            {
                for(int j = 0; j < n; j++) a[j][op[i].se] *= -1;
            }
        }
    }
    if(res == 2 * n + 10) res = -1;
    cout << res;
}
void sub3()
{
    int res = 2 * n + 10;
    for(int mask = 0; mask < BIT(n); mask++)
    {
        for(int i = 0; i < n; i++) if(MASK(mask, i))
        {
            for(int j = 0; j < n; j++) a[i][j] *= -1;
        }
        bool isAns = 1;
        int numCol = 0;
        for(int j = 0; ((j < n) && (isAns)); j++)
        {
            bool ok = 1, ok1 = 1;
            for(int i = 0; i < n; i++)
            {
                if(a[i][j] != 0) ok &= (a[i][j] != b[i][j]);
                ok1 &= (a[i][j] == b[i][j]);
            }
            isAns &= ((ok)||(ok1));
            numCol += ok;
        }
        if(isAns) res = min(res, (int)__builtin_popcount(mask) + numCol);
        for(int i = 0; i < n; i++) if(MASK(mask, i))
        {
            for(int j = 0; j < n; j++) a[i][j] *= -1;
        }
    }
    if(res == 2 * n + 10) res = -1;
    cout << res;
}
void process(int tc = 0)
{
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    {
        int tmp1 = a[i][j];
        int tmp2 = b[i][j];
        if(tmp2 == 0) swap(tmp1, tmp2);
        if(tmp1 == 0 && tmp2 != 0)
        {
            cout << -1;
            return;
        }
    }
    if(n <= 20) sub3();
}

int main()
{
    fastio();
    int tc = 1;
    //cin >> tc;
    for(int i = 1; i <= tc; i++)
    {
        init();
        process(i);
    }
    cerr << "TIME1 : " << TIME << "s\n";
    return 0;
}
