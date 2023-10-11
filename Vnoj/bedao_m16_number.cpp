// Onegai no bug
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

const int N = 1e5+ 5;
const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, a[N], k;
ll dp[N][35];
void add(ll &a,const ll &b)
{
    a += b;
    while(a >= MOD)a-=MOD;
}
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    cin >> k;
}
void process(void)
{
    FOR(i,1,n)
    {
        dp[i][1] = dp[i - 1][1];
        if(a[i] != 0 && k > 1)add(dp[i][1],1);
       FOR(j,2,min(i, k - 1))
       {
           dp[i][j] = dp[i - 1][j];
           add(dp[i][j], dp[i - 1][j - 1]);
       }
       dp[i][k] = dp[i - 1][k];
       if(a[i]%2 == 0)
            if(k > 1)add(dp[i][k],dp[i - 1][k - 1]);
            else add(dp[i][k], 1);
//       FOR(j,1,k)
//            cout << i << " " << j << " " << dp[i][j] << endl;
    }
    cout << dp[n][k];
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


