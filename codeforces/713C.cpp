// Onegai no bug
// Author : Nyanpasuuuuu
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
#define endl '\n'
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

const int N = 3e3 + 5;
const ll mod =1e18+9;
//const ll base = 311;
//const int bl = 488;

int n;
ll dp[N][N], a[N];
vector<int>vec;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    FOR(i,1,n)
    {
       cin >> a[i];
       a[i] -= i;
       vec.pb(a[i]);
    }
    sort(all(vec));
    memset(dp,0x3f,sizeof dp);
    FOR(i,0,n)dp[0][i] = 0;
    FOR(i,1,n)
    {
        REP(j,0,SZ(vec))dp[i][j] = min(dp[i][j],dp[i-1][j] + abs(a[i] - vec[j]));
        REP(j,1,SZ(vec))dp[i][j] = min(dp[i][j],dp[i][j-1]);
    }
    ll ans= mod;
    REP(j,0,SZ(vec))minimize(ans,dp[n][j]);
    cout << ans;
}

