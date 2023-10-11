// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "cbarn"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e3 + 5;
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, k, a[N];
ll cost[N][N], dp[2][N];
void DnC(int l, int r, int optl, int optr)
{
    if(l > r)return ;
    int mid = (l+r) >> 1;
    ll best = INF;
    int opt;
    for(int i = optl; i <= min(mid, optr); i++)
        if(minimize(best, dp[0][i] + cost[i + 1][mid]))
            opt = i;
    if(best != INF)minimize(dp[1][mid],best);
    DnC(l, mid - 1, optl, opt);
    DnC(mid + 1, r, opt, optr);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".in","r"))
    {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n)
            cin >> a[i];
        FOR(i,n + 1, 2 * n)
            a[i] = a[i - n];
        FOR(i,1,2 * n - 1)
            FOR(j, i + 1, i + n - 1)
            {
                cost[i][j] = cost[i][j - 1] + (j - i) * a[j];
                //cout << i << " " << j << " " << cost[i][j] << endl;
            }
        ll ans = INF;
        FOR(fir,1,n)
        {
            memset(dp,0x3f,sizeof dp);
            dp[0][fir] = 0;
            FOR(j, fir + 1, fir + n - 1)
                dp[0][j] = cost[fir][j];
            FOR(j, 2, k)
            {
                DnC(fir, fir + n - 1, fir, fir + n - 1);
                FOR(o,fir,fir + n - 1){
                    dp[0][o] = dp[1][o];
                    dp[1][o] = INF;
                }
            }
            minimize(ans, dp[0][fir + n - 1]);
            //cout << fir <<  " " << ans << endl;
        }
        cout << ans << endl;
    }

}

