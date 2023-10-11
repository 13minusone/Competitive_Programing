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

const int N = 2e2 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, k, a[N], dp[N][N][3], d[N];
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        cin >> d[i];
}
void process(void)
{
    memset(dp,-0x3f,sizeof dp);
    dp[0][0][0] = 0;
    FOR(i,1,n)
    {
        FOR(j,0,k)
        {
            FOR(o,0,2){
                maximize(dp[i][j][o], dp[i - 1][j][o]);
                if(j >= a[i])
                    maximize(dp[i][j][(o + (d[i] % 3)) % 3], dp[i - 1][j - a[i]][o] + 1);
            //cout << i << " " << j << " " <<(o + (d[i] % 3)) % 3 <<" " << dp[i - 1][j - a[i]][o] + 1 << " " << dp[i][j][(o + (d[i] % 3)) % 3] << endl;
            }
        }
    }
    int ans = 0;
    FOR(i,0,k)
        maximize(ans, dp[n][i][0]);
    cout << ans;
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


