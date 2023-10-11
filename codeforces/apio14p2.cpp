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

const int N = 1e5 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, k, trace[N][201], pre[N], Now = 0, a[N] ;
vector<ll>cur, tmp;
void solve(int l, int r, int optl, int optr)
{
    if(l > r)return;
    pair<ll, int>best = {-1, 0};
    int mid = (l+r) >> 1;
    FOR(i,optl, min(optr, mid))
        maximize(best, make_pair(cur[i - 1] + 1LL * (pre[mid] - pre[i - 1]) * (pre[n] - pre[mid]), i));
    trace[mid][Now] = best.se;
    tmp[mid] = best.fi;
//    cout << mid << " " << Now << " " << best.fi << " " << best.se << endl;
    solve(l, mid - 1, optl, best.se);
    solve(mid + 1, r, best.se, optr);
}
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

}
void process(void)
{
    cur.assign(n, 0);
    tmp.assign(n, 0);
    FOR(i,1,k)
    {
        Now = i;
        solve(1,n - 1, 1, n - 1);
        cur = tmp;
        tmp.assign(n , 0);
    }
    ll ans = -INF;
    int u = -1, l = k;
    FOR(i,1,n - 1)
        if(maximize(ans, cur[i]))
            u = i;
    cout << ans << endl;
    vector<int>vec;
    vec.pb(u);
    while(l > 1)
    {
        vec.pb(trace[u][l] - 1);
        u = trace[u][l] - 1;
        l--;
    }
    //cout << SZ(vec) << endl;
    reverse(all(vec));
    for(int i : vec)
        cout << i << " " ;
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


