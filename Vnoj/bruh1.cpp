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

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
fas
ll dp[20][200][2], l, r;
bool IsPrime[200];
vector<int>digit;
vector<ll>vec;
ll calc(int i, int sum, bool tight){
    if(i == SZ(digit))return IsPrime[sum];
    if(sum > 9 * 14)return 0;
    if(dp[i][sum][tight] != -1 && !tight)
        return dp[i][sum][tight];
    ll res = 0;
    for(int j = 0; j <= (tight?  digit[i] : 9); j++)
        res += calc(i + 1, sum + j, ((j == digit[i]) ?  tight : 0));
    if(!tight)dp[i][sum][tight] = res;
    return res;
}
ll Cal(ll val){
    if(val == 0)return 0;
    digit.clear();
    while(val != 0){
        digit.pb(val%10);
        val/= 10;
    }
    reverse(all(digit));
    memset(dp,-1,sizeof dp);
    return calc(0,0,1);
}
bool Prime(int val){
    if(val <= 1)return false;
        FOR(j,2,sqrt(val))
            if(val%j == 0)return false;
    return true;
}
bool check(ll val){
    int s = 0;
    if(val == 0)return 0;
    while(val != 0){
        s += (val%10);
        val/= 10;
    }
    return IsPrime[s];
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
    FOR(i,1,140){
        IsPrime[i] = Prime(i);
    }
    memset(dp,-1,sizeof dp);
    for(ll i = 1; i <= 1e7; i++){
        if(check(1LL * i * i))vec.pb(1LL * i * i);
    }
    while(t--)
    {
        cin >> l >> r;
        int kl = lower_bound(all(vec), l) - vec.begin();
        int kr = upper_bound(all(vec), r) - vec.begin();
        cout << Cal(r) - Cal(l-1) -(kr - kl) << endl;
    }

}

