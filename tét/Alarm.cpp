// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "test"
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
const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, k, x[N], y[N], C,D,e1,e2,f;
ll a[N];
void init(void)
{
    cin >> n >> k >> x[1] >> y[1] >> C >> D >> e1 >> e2 >> f;
    FOR(i,1,n)
    {
        if(i > 1)
        {
            x[i] = (1LL * C * x[i - 1] % f + 1LL * D * y[i-1] % f + e1) %f;
            y[i] = (1LL * D * x[i - 1] % f + 1LL * C * y[i-1] % f + e2) %f;
        }
        a[i] = (x[i] + y[i])%f;
    }
}
void add(ll &x, const ll y)
{
    x += y;
    while(x >= MOD)x -= MOD;
}
int pw(int x, int y)
{
    int res = 1;
    while(y)
    {
        if(y & 1) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y /= 2;
    }
    return res;
}
void sub1()
{
    ll res = 0;
    FOR(i,1,k)
    {
        FOR(l,1,n) FOR(r,l,n)
        {
            FOR(t,l,r)add(res, 1LL * a[t] * pw(t-l+1, i)%MOD);
        }
    }
    cout << res << endl;;
}
void process(void)
{
    sub1();
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
    cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


