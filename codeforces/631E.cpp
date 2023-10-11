// Author : Nyanpasuuuuu
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
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
/*
    dp[i] = max(a[i] * j  - pre[j])  + pre[i] - a[i] * i (j > i);
    dp[i] = max(a[i] * j  - pre[j - 1])  + pre[i - 1] - a[i] * i( j < i);
*/
int n, a[N], sz = 0;
ll ans = 0;
ll pre[N], sum[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        sum[i] = sum[i - 1] + 1LL * a[i] * i;
    }
}
struct Line
{
    ll a, b;
    Line(ll _a = 0, ll _b =0){
        a = _a;
        b = _b;
    }
    ll getVal(ll x)
    {
        return (1LL * x * a + b);
    }
}S[N];
bool bad(Line a, Line b, Line c)
{
    //return (double)(b.b - a.b) / (a.a - b.a) <= (double)(c.b - a.b) / (a.a - c.a);
    return (c.b - a.b) * (a.a - b.a) <= (b.b - a.b) * (a.a - c.a);
    //(p3.se - p1.se) * (p1.fi - p2.fi) > (p2.se - p1.se) * (p1.fi - p3.fi)
    // (c.b - a.b) * (a.a - b.a) >= (b.b - a.b) / (a.a - b.a)
}
void InsertLine(Line a)
{
    while(sz >= 2 && bad(S[sz - 1], S[sz], a))--sz;
    S[++sz] = a;
}
ll getMax(ll x)
{
    int l = 0, r = sz;
    while(l < r - 1)
    {
        int mid = (l+r) >> 1;
        if(S[mid].getVal(x) <= S[mid + 1].getVal(x))l = mid;
        else r = mid;
    }
    return S[r].getVal(x);
}
void process(void)
{
    sz = 0;
    InsertLine(Line(1,-pre[0]));
    FOR(i,2,n)
    {
        maximize(ans, getMax(a[i]) + pre[i - 1] - 1LL * a[i] * i);
        InsertLine(Line(i, -pre[i - 1]));
    }
    sz = 0;
    InsertLine(Line(-n,- pre[n]));
    FD(i,n - 1, 1)
    {
        maximize(ans, getMax(-a[i]) + pre[i] - 1LL * a[i] * i);
        InsertLine(Line(-i, -pre[i]));
    }
    cout << sum[n] + ans << endl;
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
