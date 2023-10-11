/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "test"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define mp make_pair
#define MASK(x, i) (((x) >> (i))&1)
typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if (fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(1e5) + 10;
const int INF = 1e9;
int n, k, a[N];
ii dp[N][5];
void init()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        --a[i];
        if(a[i] < 0) a[i] = 2;
    }
}
void minimize(ii &a, ii b)
{
    if(min(a.fi,b.fi) == b.fi)
    {
        if(a.fi == b.fi)
            a.se = max(a.se, b.se);
        else a.se = b.se;
        a.fi = b.fi;

    }
}
void process(const int &tc)
{
    for(int i = 1; i <= n; i++)
        dp[i][1] = dp[i][0] = ii(INF,0);
    dp[0][0] = dp[0][1] = ii(0,-INF);
    for(int i = 0;i <n; i++)
    {
        if(a[i + 1] == 2){
            if(i + 1 - dp[i][1].se + 1 <= k)
                minimize(dp[i + 1][1], dp[i][1]);
            else{
                minimize(dp[i + 1][1], ii(dp[i][1].fi + 1, i + 1));
                minimize(dp[i + 1][0], ii(dp[i][1].fi + 1, i + 1));
            }
            if(i + 1 - dp[i][0].se + 1 <= k)
                minimize(dp[i + 1][0], dp[i][0]);
            else{
                minimize(dp[i + 1][0], ii(dp[i][0].fi + 1, i + 1));
                minimize(dp[i + 1][1], ii(dp[i][0].fi + 1, i + 1));
            }
        }
        else
        {
            if(i + 1 - dp[i][a[i + 1]].se  + 1 <= k)
                minimize(dp[i + 1][a[i + 1]],dp[i][a[i + 1]]);
            else{
                minimize(dp[i + 1][a[i + 1]], ii(dp[i][a[i + 1]].fi + 1, i + 1));
            }
            int bit = 1 - a[i + 1];
            int near = dp[i][bit].se;
            if(i + 1 - near + 1 <= k)
                minimize(dp[min(n,near + k-1)][a[i +1]], ii(dp[i][bit].fi + 1,i + 1));
            else
                minimize(dp[i + 1][a[i + 1]], ii(dp[i][1 - a[i + 1]].fi + 1, i + 1));
        }
//        cout <<i << " " <<  dp[i][0].fi << " " << dp[i][0].se<< endl;
//        cout <<i << " "<<  dp[i][1].fi << " " << dp[i][1].se<< endl;
    }
    cout << min(dp[n][1].fi, dp[n][0].fi);
}
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
