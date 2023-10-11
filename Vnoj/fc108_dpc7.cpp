// Onegai no bug
// Author : 13minusone
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

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, x, a[N];
ll dp[N][4];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> x;
    FOR(i,1,n)
    {
        cin >> a[i];
    }
    ll res = 0;
    FOR(i,1,n)
    {
        dp[i][0] = max(0LL,dp[i-1][0] + a[i]);
        dp[i][1] = max(0LL,max(dp[i-1][1], dp[i-1][0]) + a[i] * x);
        dp[i][2] = max(0LL,max(dp[i-1][1], dp[i-1][2]) + a[i]);
        res = max({res,dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << res << endl;
}

