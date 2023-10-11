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

const int N = 2e3 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

ll dp[N][N], ans = 0, n, a[N], l, r;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    FOR(i,1,n)cin >> a[i];
    FD(i,n,1)dp[0][i] = dp[0][i+1] + (n-i+1) * a[i];
    FOR(i,1,n)dp[i][n+1] = dp[i-1][n+1] + i * a[i];
    FOR(i,1,n)
        FD(j,n,i+1)
        {
            maximize(dp[i][j],max(dp[i-1][j] + (n-j+1+i) * a[i], dp[i][j+1] + (i+n-j +1) * a[j]));
            if(maximize(ans,dp[i][j]))
            {
                l = i, r= j;
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    cout << ans << endl;
    vector<int>vec;
    while(l >= 0 && r <= n+1)
    {
        //cout << 1 << endl;
        //cout << l << " " << r << endl;
        if(l > 0 && dp[l-1][r]  + (n-r+1 + l) * a[l] == dp[l][r])
        {
            vec.pb(l);
            l--;
        }
        ////cout << l << endl;
        if(r < n + 1 && dp[l][r+1] + (n-r+1 + l) * a[r] == dp[l][r])
        {
            vec.pb(r);
            r++;
        }
        //cout << r << endl;
        if(l ==0 && r == n+1)break;
    }
    //int res = 0, cnt = 0;
    FD(i,n-1,0){
        //cnt++;
        //res += a[vec[i]] *cnt;
        cout << vec[i] << " " ;
    }
    //cout << endl << res << endl;
}

