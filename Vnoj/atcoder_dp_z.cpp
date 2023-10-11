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
typedef pair<int,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e18 + 7;
/*
    dp[i] = min(dp[j] + (h[i] - h[j])^2 + c)
    => dp[i] = min(dp[j] + h[i] ^ 2 + h[j] ^ 2 - 2 * h[i] * h[j] + c)
    => dp[i] = min(dp[j] + h[j] ^ 2 - 2 * h[i] * h[j] + c) + h[i] ^ 2;
*/
int n, h[N], cnt = 0;
ll c, dp[N];
ii vec[N];
ll getVal(int x, int id)
{
    if(id > cnt)return INF;
    return (1LL * x * vec[id].fi + vec[id].se);
}
bool ccw(ii a, ii b, ii c)
{
    return ((double)(a.fi - b.fi)/ (b.se - a.se)) < ((double)(a.fi - c.fi) / (c.se - a.se));
}
void InsertLine(ii c)
{
    while(cnt >= 2 && ccw(vec[cnt - 1], vec[cnt], c))
        cnt--;
    vec[++cnt] = c;
}
ll FindD(int x)
{
    int l = 1, r = cnt;
    while(l < r)
    {
        int mid = (l+r) >> 1;
        int mid2 = mid + 1;
        if(getVal(x, mid) < getVal(x, mid2))
        {
            r = mid;
        }
        else l = mid + 1;
    }
    //cout << x << " " << r << endl;
    return getVal(x, r);
}
void init(void)
{
    cin >> n >> c;
    FOR(i,1,n)
        cin >> h[i];
}
void process(void)
{
    InsertLine(ii(-2 * h[1], 1LL * h[1] * h[1]));
    dp[1] = 0;
    FOR(i,2,n)
    {
        dp[i] = FindD(h[i]) + c + 1LL * h[i] * h[i];
       // cout << dp[i] << endl;
        InsertLine(ii(-2 * h[i], 1LL * h[i] * h[i] + dp[i]));
    }
    cout << dp[n];
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

