// Onegai no bug
// Author :13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
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

const int N = 1e5+ 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

ll n, k, l = 1, r = 0, cnt = 0, d[N], a[N];
vector<ll>dp(N+1),dp_cur(N+1);
void del(int id)
{
    cnt -= (1LL * d[a[id]] * (d[a[id]]-1)/2);
    d[a[id]]--;
    cnt += (1LL * d[a[id]] * (d[a[id]]-1)/2);
}
void add(int id)
{
    cnt -= (1LL * d[a[id]] * (d[a[id]]-1)/2);
    d[a[id]]++;
    cnt += (1LL * d[a[id]] * (d[a[id]]-1)/2);
}
void cal(int L, int R)
{
    while(l < L)del(l++);
    while(r < R)add(++r);
    while(r > R)del(r--);
    while(l > L)add(--l);
}
void compute(int l,int r,int optl, int optr)
{
    if(l > r)return;
    int mid = (l+r) >> 1;
    ii best = ii(mod,-1);
    FOR(i,optl,min(mid,optr))
    {
        cal(i,mid);
        best = min(best,ii(dp[i-1]+cnt,i));
    }
    dp_cur[mid] = best.fi;
    compute(l, mid - 1, optl, best.se);
    compute(mid+1, r, best.se, optr);
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
    cin >> n >> k;

    FOR(i,1,n)cin >> a[i];
    FOR(i,1,n)cal(1,i),dp[i] = cnt;
    FOR(i,2,k)
    {
        compute(1, n, 1, n);
        dp = dp_cur;
    }
    cout << dp[n];
}



