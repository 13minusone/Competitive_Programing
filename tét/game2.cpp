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

const int N = 1e2 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, a[4][N], dp[N][N][N][N], cnt[4];
vector<int>val[4];
void init(void)
{
    cin >> n;
    FOR(i,1,3)
        FOR(j,1,n){
            cin >> a[i][j];
             if(a[i][j] == 0)
                ++cnt[i];
            else
                val[i].emplace_back(a[i][j]);
        }


}
void process(void)
{
    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0][0] = 0;
    REP(i,0,n)
        FOR(x,0,min(i, cnt[1]))
        FOR(y,0,min(i, cnt[2]))
        FOR(z,0,min(i, cnt[3]))
            if(dp[i][x][y][z] >= -INF)
                REP(a,0,2)
                    REP(b,0,2)
                        REP(c,0,2)
                            if(a + b + c > 0)
                                maximize(dp[i + 1][x + a][y + b][z + c],dp[i][x][y][z]);
                            else
                                maximize(dp[i + 1][x][y][z],dp[i][x][y][z] + val[1][i - x] * val[2][i - y] * val[3][i - z]);
    cout << dp[n][cnt[1]][cnt[2]][cnt[3]];
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


