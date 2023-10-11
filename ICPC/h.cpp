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

string l, r;
int nl, nr;
ll calc(int i, int sum, bool tight){
    if(i == nr)return sum == s;
    if(sum > s)return 0;
    if(dp[i][sum][tight] != -1)
        return dp[i][sum][tight];
    ll res = 0;
    for(int j = a[i]; j <= (tight?  b[i] : 9); j++)
        res += calc(i + 1, sum + j, ((j == digit[i]) ?  tight : 0));
    dp[i][sum][tight] = res;
    return res;
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
    //cin >> t;
    while(t--)
    {
        cin >> l >> r;
        nl = SZ(l);
        nr = SZ(r);
         l = " " + l;
         r = " " + r;
         FOR(i,1,nl)
            a[i] = int(l[i] - '0');
        FOR(i,1,nr)
            b[i] = int(r[i] - '0');
    }

}

