// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "line"
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
const ll mod = 998244353;
//const ll base = 311;
//const int bl = 488;

void add(ll &a,const ll &b)
{
    a += b;
    if(a >= mod)a-=mod;
}
ll dp[2][305], cnt[305];
int  d[N], n, k;
ll fact[N], ifact[N];
ll powe(int a, int b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    ll t = powe(a, b/2);
    if(b &1)return 1LL * (1LL * t * t%mod) * a %mod;
    else return 1LL * t * t %mod;
}
ll C(int k, int n)
{
    if(k > n)return 0;
    return 1LL * (1LL * fact[n] * ifact[n-k] %mod) * ifact[k]%mod;
}
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
    int t;
    cin >> t;
    cin >> n >> k;
    FOR(i,1,n){
        int x;
        cin >> x;
        d[x]++;
        vec.pb(x);
    }
    sort(all(vec), greater<int>());
    vec.resize(unique(all(vec)) - vec.begin());
    fact[0] = 1;
    FOR(i,1,n)
        fact[i] = (1LL * fact[i-1] * i)%mod;
    ifact[n] = powe(fact[n], mod-2);
    FD(i,n-1, 0)
        ifact[i] = (1LL * ifact[i+1] * (i+1))%mod;
    dp[0][0] = 1;
    int pref = 0;
    for(int i : vec){
            memset(cnt,0,sizeof cnt);
        FOR(j,1,min(k,d[i]))
            FOR(o,1,min(min(k,j), pref))
            {
                add(cnt[j],1LL * (1LL * C(o-1,j-1) * fact[d[i]] % mod) * C(o, pref)%mod);
            }
//        FOR(j,1,min(k,j))cout << cnt[j] << " " ;
//        cout << endl;
        pref += d[i];
        cnt[0] = fact[d[i]];
        FOR(j,0, k)
            FOR(o,0,min(k-j,d[i]))
                add(dp[1][j+o], 1LL * dp[0][j] * cnt[o] %mod);
        swap(dp[0] ,dp[1]);
        memset(dp[1], 0, sizeof dp[1]);

    }
        //FOR(j,0,k)cout << dp[0][j] << " ";
    ll res = 0;
    FOR(i,0,k)
        add(res, dp[0][i]);
    cout << res << endl;
}

