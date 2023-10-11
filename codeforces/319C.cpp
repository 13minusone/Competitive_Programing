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
typedef unsigned long long ull ;
typedef pair<ull,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e5 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const ull INF = 1e20 + 7;
int n, a[N], b[N];
ull dp[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        cin >> b[i];
}
void solve(int l, int r, int optl, int optr)
{
    if(l > r)return;
    int mid = (l+r) >> 1;
    ii best = ii(INF, -1);
    FOR(k,optl, min(optr, mid - 1))
        minimize(best, ii(dp[k] + 1ULL * a[mid] * b[k], k));
   // cout << mid << " "<<optl << " "<< optr<< " " << best.fi << " " << best.se << endl;
    dp[mid] = best.fi;
    int opt = best.se;
    solve(l, mid-1, optl, opt);
    solve(mid + 1, r, opt, optr);
}
void process(void)
{
    memset(dp,0x3f,sizeof dp);
    dp[1] = 0;
    FOR(i,2,n)
        dp[i] = (1ULL * a[i] * b[1]);
    solve(2,n,1,n);
    cout << dp[n];
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
