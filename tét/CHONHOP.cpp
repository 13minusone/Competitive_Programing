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

const int N = 2e6 + 5;
const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, sum[N], f[N], m;
void add(ll &a, const ll b)
{
    a += b;
    while(a >= MOD) a-= MOD;
}
ll Pow(int a, int b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    ll t = Pow(a, b/2);
    if(b & 1)return 1LL *(1LL * t * t % MOD)*a % MOD;
    else return (1LL * t * t) % MOD;
}
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
    {
        register int k;
        cin >> k;
        FOR(j,1,k)
        {
            register int x;
            cin >> x;
            sum[i] += (1 << (x - 1));
        }
//       cout << sum[i] << endl;
        f[sum[i]]++;
    }
}
void process(void)
{
    FOR(i,0,m - 1)
        FOR(j,0,(1 << m) - 1)
            if(getbit(j, i))
                f[j] += f[j ^(1 << i)];
    ll ans = 0;
    FOR(i,0,(1 << m) - 1)
    {
        int cnt = __builtin_popcount(i);
        if(cnt &1) ans = (ans - Pow(2, f[(1 << m) - 1 - i]) + 1 +   MOD) % MOD;
        else ans = (ans + Pow(2, f[(1 << m) - 1 - i]) - 1 +  MOD) %  MOD;
    }
    cout << ans << endl;
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


