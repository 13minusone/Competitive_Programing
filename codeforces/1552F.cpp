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

const int N = 1e6 + 5;
const int MOD =998244353;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, x[N], y[N];
ll pre[N], ans = 0;
bool s[N];
vector<int>val;
void add(ll& a,const ll &b)
{
    a += b;
    while(a >= MOD) a-= MOD;
}
void init(void)
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> x[i] >> y[i] >> s[i];
        val.pb(x[i]);
    }
}
void process(void)
{
    FOR(i,1,n)
    {
        int k = lower_bound(all(val), y[i]) - val.begin();
        if(s[i])add(ans, ((pre[i - 1] - pre[k] + MOD)%MOD + x[i] - y[i])%MOD);
        pre[i] = pre[i - 1];
        add(pre[i], ((pre[i - 1] % MOD + x[i] - y[i]) %MOD - pre[k] + MOD) %MOD);
       // cout << i << " " << ans << " " << pre[i + 1] << endl;
    }
    add(ans, 1 + x[n]);
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


