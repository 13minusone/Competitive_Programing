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

const int N = 19 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

ll l, r, dp[N][173][3];
int s;
vector<int>digit;
ll calc(int i, int sum, bool tight){
    if(i == SZ(digit))return sum == s;
    if(sum > s)return 0;
    if(dp[i][sum][tight] != -1)
        return dp[i][sum][tight];
    ll res = 0;
    for(int j = 0; j <= (tight?  digit[i] : 9); j++)
        res += calc(i + 1, sum + j, ((j == digit[i]) ?  tight : 0));
    dp[i][sum][tight] = res;
    return res;
}
ll cal( int i,ll val){
    if(val == 0)return 0;
    digit.clear();
    while(val != 0){
        digit.pb(val%10);
        val/= 10;
    }
    reverse(all(digit));
    memset(dp,-1,sizeof dp);
    s = i;
    return calc(0,0,1);
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
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        ll ans = 0;
        FOR(i,1,171){
            ll le = ((l-1)/ i), ri = (r/i);
            ans += cal(i,ri) - cal(i,le);
        }
        cout << ans << endl;
    }

}

