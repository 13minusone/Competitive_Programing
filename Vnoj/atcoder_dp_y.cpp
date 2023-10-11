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
const ll MOD =1e9+7;
//const ll base = 311;
//const int bl = 488;

int h, w, n;
ll  fac[N],ifac[N], dp[N];
ii a[N];
int power(long long x, int p) {
    long long res = 1;
    while (p > 0) {
        if (p & 1) res = res * x % MOD;
        x = x * x % MOD, p >>= 1;
    }
    return res%MOD;
}

void genFac(int s) {
    fac[0] = 1;
    for (int i = 1; i <= s; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    ifac[s] = power(fac[s], MOD - 2);
    for (int i = s; i >= 1; --i)
        ifac[i - 1] = ifac[i] * i % MOD;
}
int C(int n, int k) {
    assert(n >= k);
    //if(n == k)return 1;
    return (1LL * (1LL *fac[n] * ifac[k]) % MOD * ifac[n - k]) % MOD;
}
void add(int &a, const int &b)
{
    a += b;
    while(a >= MOD)a-=MOD;
}
bool cmp(ii a, ii b)
{
    if(a.fi != b.fi)return a.fi < b.fi;
    else return a.se < b.se;
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
    cin >> h>> n;
    FOR(i,1,n)
    {
        cin >> a[i].fi >> a[i].se;
    }
    genFac(h + h-1);
    a[n+1] = ii(h,h);
    sort(a + 1, a + 1+ n,cmp);
    //cout << C(3,2)<<endl;
    FOR(i,1,n+1)
    {
        int ans = 0;
        add(ans,C(a[i].fi + a[i].se -2, a[i].fi-1));
        FD(j,i-1,1)
        {
            if(a[j].se <= a[i].se)
            {
                ans -= (1LL * dp[j]* C(a[i].fi - a[j].fi + a[i].se - a[j].se, a[i].fi - a[j].fi) % MOD) ;
                if(ans < 0)ans += MOD;
            }
        }
        //cout << ans << endl;
        dp[i] = ans;
    }
    cout << dp[n+1];

}

